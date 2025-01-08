/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehedeman <ehedeman@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 12:36:18 by ehedeman          #+#    #+#             */
/*   Updated: 2025/01/08 14:40:50 by ehedeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static void	move_player_up_down(t_player *player, float sin_angle, \
	float cos_angle, t_map *map)
{
	if (player->key_up)
	{
		if (!is_wall(player, map))
		{
			player->x += cos_angle * SPEED;
			player->y += sin_angle * SPEED;
		}
		if (!touch(player->x, player->y + sin_angle * SPEED, map))
			player->y += sin_angle * SPEED;
		if (!touch(player->x + cos_angle * SPEED, player->y, map))
			player->x += cos_angle * SPEED;
	}
	if (player->key_down)
	{
		if (!is_wall(player, map))
		{
			player->x -= cos_angle * SPEED;
			player->y -= sin_angle * SPEED;
		}
		if (!touch(player->x, player->y - sin_angle * SPEED, map))
			player->y -= sin_angle * SPEED;
		if (!touch(player->x - cos_angle * SPEED, player->y, map))
			player->x -= cos_angle * SPEED;
	}
}

static void	move_player_left_right(t_player *player, float sin_angle, \
	float cos_angle, t_map *map)
{
	if (player->key_left)
	{
		if (!is_wall(player, map))
		{
			player->x += sin_angle * SPEED;
			player->y -= cos_angle * SPEED;
		}
		if (!touch(player->x + sin_angle * SPEED, player->y, map))
			player->x += sin_angle * SPEED;
		if (!touch(player->x, player->y - cos_angle * SPEED, map))
			player->y -= cos_angle * SPEED;
	}
	if (player->key_right)
	{
		if (!is_wall(player, map))
		{
			player->x -= sin_angle * SPEED;
			player->y += cos_angle * SPEED;
		}
		if (!touch(player->x - sin_angle * SPEED, player->y, map))
			player->x -= sin_angle * SPEED;
		if (!touch(player->x, player->y + cos_angle * SPEED, map))
			player->y += cos_angle * SPEED;
	}
}

static void	avoid_glitch_into_cubes(t_player *player, t_map *map, \
	t_coordinates *old)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->length - 2)
	{
		j = 0;
		while (j < map->width - 1)
		{
			if (map->map[i][j] == '1')
			{
				if (((int)player->x / BLOCK) == j && \
					((int)player->y / BLOCK) == i)
				{
					player->x = old->x;
					player->y = old->y;
				}
			}
			j++;
		}
		i++;
	}
}

static void	avoid_to_glitch_into_wall(t_player *player, t_map *map, \
	t_coordinates *old)
{
	if (((int)player->x / BLOCK) >= map->width - 2)
		player->x = (map->width - 2.1) * BLOCK;
	if (((int)player->y / BLOCK) >= map->length - 2)
		player->y = (map->length - 2.1) * BLOCK;
	if (((int)player->x / BLOCK) <= 0)
		player->x = 1 * BLOCK;
	if (((int)player->y / BLOCK) <= 0)
		player->y = 1 * BLOCK;
	avoid_glitch_into_cubes(player, map, old);
}

void	move_player(t_player *player, t_map *map)
{
	float			angle_speed;
	t_coordinates	old_pos;

	angle_speed = 0.03;
	player->cos_angle = cos(player->angle);
	player->sin_angle = sin(player->angle);
	old_pos.x = player->x;
	old_pos.y = player->y;
	if (player->left_rotate)
		player->angle -= angle_speed;
	if (player->right_rotate)
		player->angle += angle_speed;
	if (player->angle > 2 * PI)
		player->angle = 0;
	if (player->angle < 0)
		player->angle = 2 * PI;
	move_player_up_down(player, player->sin_angle, player->cos_angle, map);
	move_player_left_right(player, player->sin_angle, player->cos_angle, map);
	avoid_to_glitch_into_wall(player, map, &old_pos);
}
