/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehedeman <ehedeman@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 12:34:53 by ehedeman          #+#    #+#             */
/*   Updated: 2025/01/08 14:41:32 by ehedeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static	void	change_x_y(t_player *player, int *x, int *y)
{
	if (player->key_up)
	{
		*x = player->x + player->cos_angle * SPEED;
		*y = player->y + player->sin_angle * SPEED;
	}
	if (player->key_down)
	{
		*x = player->x - player->cos_angle * SPEED;
		*y = player->y - player->sin_angle * SPEED;
	}
	if (player->key_left)
	{
		*x = player->x + player->sin_angle * SPEED;
		*y = player->y - player->cos_angle * SPEED;
	}
	if (player->key_right)
	{
		*x = player->x - player->sin_angle * SPEED;
		*y = player->y + player->cos_angle * SPEED;
	}
}

int	is_wall(t_player *player, t_map *map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	change_x_y(player, &x, &y);
	if (y / BLOCK > map->length - 2 || x / BLOCK > map->width - 2
		|| y / BLOCK < 0 || x / BLOCK < 0)
		return (1);
	if (map->map[y / BLOCK][x / BLOCK] != '0')
		return (1);
	if (map->map[y / BLOCK][(int)player->x / BLOCK] != '0'
		|| map->map[(int)player->y / BLOCK][x / BLOCK] != '0')
		return (1);
	return (0);
}
