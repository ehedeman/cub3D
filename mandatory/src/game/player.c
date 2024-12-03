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
	// player->start.x = (map->length);
	// player->start.y = 1;
	player->x = (WIDTH / map->width) * player->start.x;
	player->y = (HEIGHT / map->length) * player->start.y;// is ok
	printf("Current player Coordinates in float (y | x): %f | %f\n", player->y, player->x);
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
	//printf("%i %i %i %i\n", (int)player->x /BLOCK, (int)player->y /BLOCK, map->width, map->length - 1);
	if (y / BLOCK > map->length - 1 || x / BLOCK > map->width 
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
	int	speed;
	int	wall;

	speed = 2;
	wall = is_wall(player, sin_angle, cos_angle, map);
	if (player->key_up)
	{
		if (!wall)
		{
			player->x += cos_angle * speed;
			player->y += sin_angle * speed;
		}
		else if (wall)
			player->x += cos_angle * speed;
	}
	if (player->key_down)
	{
		if (!wall)
		{
			player->x -= cos_angle * speed;
			player->y -= sin_angle * speed;
		}
		else if (wall)
			player->x -= cos_angle * speed;
	}
}

void	move_player_left_right(t_player *player, float sin_angle, float cos_angle, t_map *map)
{
	int	speed;
	int	wall;

	speed = 1;
	wall = is_wall(player, sin_angle, cos_angle, map);
	if (player->key_left)
	{
		if (!wall)
		{
			player->x += sin_angle * speed;
			player->y -= cos_angle * speed;
		}
		else if (wall == 1)
			player->y += cos_angle * speed;
	}
	if (player->key_right)
	{
		if (!wall)
		{
			player->x -= sin_angle * speed;
			player->y += cos_angle * speed;
		}
		else if (wall == 1)
			player->y -= cos_angle * speed;
	}
}

void move_player(t_player *player, t_map *map)
{
	float	angle_speed;
	float	cos_angle;
	float	sin_angle;
	t_coordinates save;

	save.y = player->y;
	save.x = player->x;
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
	if (player->x / BLOCK < 0)
		player->x = 0;
	if (player->x / BLOCK > map->width)
		player->x = map->width * BLOCK;
	if (player->y / BLOCK < 0)
		player->y = 0;
	if (player->y / BLOCK > map->length - 1)
		player->y = (map->length - 1) * BLOCK;
}
