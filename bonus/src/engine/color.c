/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehedeman <ehedeman@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 14:16:10 by ehedeman          #+#    #+#             */
/*   Updated: 2025/01/03 15:05:42 by ehedeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static t_img	*figure_out_tex(t_game *game)
{
	t_img	*t;

	if (game->exit_found)
		t = game->walls.exit;
	else if (game->side == _s_north)
		t = game->walls.north;
	else if (game->side == _s_south)
		t = game->walls.south;
	else if (game->side == _s_east)
		t = game->walls.east;
	else if (game->side == _s_west)
		t = game->walls.west;
	else
		return (0);
	return (t);
}

int	get_pixel_color(float *ray_x, float *ray_y, int z, t_game *game)
{
	t_img	*t;
	char	*pixel;
	int		x;
	int		y;

	x = 0;
	y = 0;
	t = figure_out_tex(game);
	if (!t)
		return (0);
	if (game->side == _s_north || game->side == _s_south)
		x = (int)*ray_x;
	else if (game->side == _s_east || game->side == _s_west)
		x = (int)*ray_y;
	y = z + t->height / 2;
	y %= t->height;
	x %= t->width;
	if (x >= 0 && x < t->width && y >= 0 && y < t->height)
	{
		pixel = t->addr + (y * t->ll + (x * (t->bpp / 8)));
		return (*(int *)pixel);
	}
	return (0);
}
