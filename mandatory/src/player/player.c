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

# include "../includes/cub3D.h"

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
	player->angle = PI / 2;

	player->key_up = false;
	player->key_down = false;
	player->key_right = false;
	player->key_left = false;

	player->left_rotate = false;
	player->right_rotate = false;
}

int key_press(int keycode, t_game *game)
{
	if(keycode == W)
		game->player.key_up = true;
	if(keycode == S)
		game->player.key_down = true;
	if(keycode == A)
		game->player.key_left = true;
	if(keycode == D)
		game->player.key_right = true;
	if(keycode == LEFT)
		game->player.left_rotate = true;
	if(keycode == RIGHT)
		game->player.right_rotate = true;
	if (keycode == XK_ESCAPE)
		print_error("ESC pressed\nThanks for playing\n", game, 0);
	return 0;
}

int key_release(int keycode, t_player *player)
{
	if(keycode == W)
		player->key_up = false;
	if(keycode == S)
		player->key_down = false;
	if(keycode == A)
		player->key_left = false;
	if(keycode == D)
		player->key_right = false;
	if(keycode == LEFT)
		player->left_rotate = false;
	if(keycode == RIGHT)
		player->right_rotate = false;
	return 0;
}
int	is_wall(t_player *player, float sin_angle, float cos_angle, t_map *map)
{
	int speed;
	int	x;
	int	y;

	x = 0;
	y = 0;
	speed = 2;
	if (player->key_up)
	{
		x = player->x + cos_angle * speed;
		y = player->y + sin_angle * speed;
	}
	if (player->key_down)
	{
		x = player->x - cos_angle * speed;
		y = player->y - sin_angle * speed;
	}
	if (player->key_left)
	{
		x = player->x + sin_angle * speed;
		y = player->y - cos_angle * speed;
	}
	if (player->key_right)
	{
		x = player->x - sin_angle * speed;
		y = player->y + cos_angle * speed;
	}
	if (map->coordinates[y / BLOCK][x / BLOCK] == '1')
		return (1);
	return (0);
}

void	move_player_up_down(t_player *player, float sin_angle, float cos_angle, t_map *map)
{
	int	speed;

	speed = 2;
	if (player->key_up)
	{
		if (!is_wall(player, sin_angle, cos_angle, map))
		{
			player->x += cos_angle * speed;
			player->y += sin_angle * speed;
		}
	}
	if (player->key_down)
	{
		if (!is_wall(player, sin_angle, cos_angle, map))
		{
			player->x -= cos_angle * speed;
			player->y -= sin_angle * speed;
		}
	}
}

void	move_player_left_right(t_player *player, float sin_angle, float cos_angle, t_map *map)
{
	int	speed;

	speed = 2;
	if (player->key_left)
	{
		if (!is_wall(player, sin_angle, cos_angle, map))
		{
			player->x += sin_angle * speed;
			player->y -= cos_angle * speed;
		}
	}
	if (player->key_right)
	{
		if (!is_wall(player, sin_angle, cos_angle, map))
		{
			player->x -= sin_angle * speed;
			player->y += cos_angle * speed;
		}
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
}
