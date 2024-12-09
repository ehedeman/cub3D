/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ****.c		                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ****** <******@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 12:33:17 by ******           #+#    #+#              */
/*   Updated: 2024/10/11 13:09:41 by ******           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	ft_set_player_location(t_map *map, t_player *player)
{
	int i = 0;
	int j;
	while (i < map->length)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->coordinates[i][j] == 'N' \
				|| map->coordinates[i][j] == 'S' \
					|| map->coordinates[i][j] == 'W' \
						|| map->coordinates[i][j] == 'E')
			{
				player->orientation = map->coordinates[i][j];
				player->start.x = j;
				player->start.y = i;
				player->start.type = map->coordinates[i][j];
				return ;
			}
			j++;
		}
		i++;
	}
}

void init_player(t_player *player, t_map *map)
{
	ft_set_player_location(map, player);
	// player->start.x = 1;
	// player->start.y = 1;
	player->x = (WIDTH / map->width) * player->start.x;
	player->y = (HEIGHT / map->length) * player->start.y;// is ok
	printf("Current player Coordinates in float (y | x): %f | %f\n", player->y, player->x);
	if (player->orientation == 'N')
		player->angle = 3 * PI / 2 + 0.0001;
	else if (player->orientation == 'S')
		player->angle = PI / 2;
	else if (player->orientation == 'W')
		player->angle = PI;
	else if (player->orientation == 'E')
		player->angle = 0;

	player->key_up = false;
	player->key_down = false;
	player->key_right = false;
	player->key_left = false;

	player->left_rotate = false;
	player->right_rotate = false;
}

int ft_key_press(int keycode, t_game *game)
{
	if(keycode == KEY_W)
		game->player.key_up = true;
	if(keycode == KEY_S)
		game->player.key_down = true;
	if(keycode == KEY_A)
		game->player.key_left = true;
	if(keycode == KEY_D)
		game->player.key_right = true;
	if(keycode == KEY_LEFT)
		game->player.left_rotate = true;
	if(keycode == KEY_RIGHT)
		game->player.right_rotate = true;
	if (keycode == KEY_ESC)
		print_error("ESC pressed\nThanks for playing\n", game, 0);
	return 0;
}

int ft_key_release(int keycode, t_player *player)
{
	if(keycode == KEY_W)
		player->key_up = false;
	if(keycode == KEY_S)
		player->key_down = false;
	if(keycode == KEY_A)
		player->key_left = false;
	if(keycode == KEY_D)
		player->key_right = false;
	if(keycode == KEY_LEFT)
		player->left_rotate = false;
	if(keycode == KEY_RIGHT)
		player->right_rotate = false;
	return 0;
}

bool is_touch(int x, int y, t_map *map)
{
	// if (x < 0 || y < 0 || x >= c->map->width * BLOCK_SIZE || y >= c->map->length * BLOCK_SIZE)
	// 	return (true);
	if (map->coordinates[y / BLOCK][x / BLOCK] == '1')
		return (true);
	return (false);
}

int	is_wall(t_player *player, float sin_angle, float cos_angle, t_map *map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (player->key_up)
	{
		x = player->x + cos_angle * SPEED;
		y = player->y + sin_angle * SPEED;
	}
	if (player->key_down)
	{
		x = player->x - cos_angle * SPEED;
		y = player->y - sin_angle * SPEED;
	}
	if (player->key_left)
	{
		x = player->x + sin_angle * SPEED;
		y = player->y - cos_angle * SPEED;
	}
	if (player->key_right)
	{
		x = player->x - sin_angle * SPEED;
		y = player->y + cos_angle * SPEED;
	}
	
	// if (map->coordinates[y / BLOCK][x / BLOCK] == '1')
	// 	return (1);

	size_t i = 0;
	size_t dist = 5;

	while (i < dist)
	{
		if(is_touch(x + dist, y, map))
		{
			player->x -= SPEED;
			return (1);
		}
		if(is_touch(x - dist, y, map))
		{
			player->x += SPEED;
			return (1);
		}
		if(is_touch(x, y + dist, map))
		{
			player->y -= SPEED;
			return (1);
		}
		if(is_touch(x, y - dist, map))
		{
			player->y += SPEED;
			return (1);
		}

		i += 1;
	}

	return (0);
}

void	move_player_up_down(t_player *player, float sin_angle, float cos_angle, t_map *map)
{
	if (player->key_up)
	{
		if (!is_wall(player, sin_angle, cos_angle, map))
		{
			player->x += cos_angle * SPEED;
			player->y += sin_angle * SPEED;
		}
	}
	if (player->key_down)
	{
		if (!is_wall(player, sin_angle, cos_angle, map))
		{
			player->x -= cos_angle * SPEED;
			player->y -= sin_angle * SPEED;
		}
	}
}

void	move_player_left_right(t_player *player, float sin_angle, float cos_angle, t_map *map)
{
	if (player->key_left)
	{
		if (!is_wall(player, sin_angle, cos_angle, map))
		{
			player->x += sin_angle * SPEED;
			player->y -= cos_angle * SPEED;
		}
	}
	if (player->key_right)
	{
		if (!is_wall(player, sin_angle, cos_angle, map))
		{
			player->x -= sin_angle * SPEED;
			player->y += cos_angle * SPEED;
		}
	}
}

void move_player(t_player *player, t_map *map)
{
	float	cos_angle;
	float	sin_angle;

	cos_angle = cos(player->angle);
	sin_angle = sin(player->angle);
	if (player->left_rotate)
		player->angle -= ROTATE_SPEED;
	if (player->right_rotate)
		player->angle += ROTATE_SPEED;
	if (player->angle > 2 * PI)
		player->angle = 0;
	if (player->angle < 0)
		player->angle = 2 * PI;
	move_player_up_down(player, sin_angle, cos_angle, map);
	move_player_left_right(player, sin_angle, cos_angle, map);
}
