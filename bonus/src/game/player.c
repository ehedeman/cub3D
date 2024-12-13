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
				map->coordinates[i][j] = '0';
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
	player->x = player->start.x * BLOCK;
	player->y = player->start.y * BLOCK;
	printf("Current player Coordinates in float (y | x): %f | %f\n", player->y, player->x);
	printf("Current player Coordinates (y | x): %i | %i\n", (int)player->y / BLOCK, (int)player->x / BLOCK);
	if (player->orientation == 'N')
		player->angle = 3 * PI / 2;
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
	if (y / BLOCK > map->length - 1 || x / BLOCK > map->width - 1
		|| y / BLOCK < 0 || x / BLOCK < 0)
		return (1);
	if (map->coordinates[y / BLOCK][x / BLOCK] != '0')
		return (1);
	if (map->coordinates[y / BLOCK][(int)player->x / BLOCK] != '0' 
		|| map->coordinates[(int)player->y / BLOCK][x / BLOCK] != '0')
		return (1);
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
		else if (!touch(player->x, player->y + sin_angle * SPEED, map->coordinates))
			player->y += sin_angle * SPEED;
		else if (!touch(player->x + cos_angle * SPEED, player->y, map->coordinates))
			player->x += cos_angle * SPEED;
	}
	if (player->key_down)
	{
		if (!is_wall(player, sin_angle, cos_angle, map))
		{
			player->x -= cos_angle * SPEED;
			player->y -= sin_angle * SPEED;
		}
		else if (!touch(player->x, player->y - sin_angle * SPEED, map->coordinates))
			player->y -= sin_angle * SPEED;
		else if (!touch(player->x - cos_angle * SPEED, player->y, map->coordinates))
			player->x -= cos_angle * SPEED;
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
		else if (!touch(player->x + sin_angle * SPEED, player->y, map->coordinates))
			player->x += sin_angle * SPEED;
		else if (!touch(player->x, player->y - cos_angle * SPEED, map->coordinates))
			player->y -= cos_angle * SPEED;
	}
	if (player->key_right)
	{
		if (!is_wall(player, sin_angle, cos_angle, map))
		{
			player->x -= sin_angle * SPEED;
			player->y += cos_angle * SPEED;
		}
		else if (!touch(player->x - sin_angle * SPEED, player->y, map->coordinates))
			player->x -= sin_angle * SPEED;
		else if (!touch(player->x, player->y + cos_angle * SPEED, map->coordinates))
			player->y += cos_angle * SPEED;
	}
}

void move_player(t_player *player, t_map *map)
{
	float	angle_speed;
	float	cos_angle;
	float	sin_angle;

	angle_speed = 0.03;
	cos_angle = cos(player->angle);
	sin_angle = sin(player->angle);
	if (player->left_rotate)
		player->angle -= angle_speed;
	if (player->right_rotate)
		player->angle += angle_speed;
	if (player->angle > 2 * PI)
		player->angle = 0;
	if (player->angle < 0)
		player->angle = 2 * PI;
	move_player_up_down(player, sin_angle, cos_angle, map);
	move_player_left_right(player, sin_angle, cos_angle, map);
	if (player->x / BLOCK <= 0)
		player->x = 1 * BLOCK;
	if (player->y / BLOCK <= 0)
		player->y = 1 * BLOCK;
	if (player->x / BLOCK >= map->width - 1)
		player->x = map->width - 2 * BLOCK;
	if (player->y / BLOCK >= map->length - 1)
		player->y = map->length - 2 * BLOCK;
}
