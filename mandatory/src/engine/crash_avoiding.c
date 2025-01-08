/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crash_avoiding.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehedeman <ehedeman@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 11:31:08 by ehedeman          #+#    #+#             */
/*   Updated: 2025/01/08 14:36:38 by ehedeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

bool	avoid_crash(t_game *game, float *ray_x, float *ray_y)
{
	if (*ray_x / BLOCK <= 0)
	{
		*ray_x = 0.1 * BLOCK;
		return (true);
	}
	if (*ray_y / BLOCK <= 0)
	{
		*ray_y = 0.1 * BLOCK;
		return (true);
	}
	if (*ray_x / BLOCK > game->map.width - 1)
	{
		*ray_x = (game->map.width - 2) * BLOCK;
		return (true);
	}
	if (*ray_y / BLOCK > game->map.length)
	{
		*ray_x = (game->map.length - 2) * BLOCK;
		return (true);
	}
	return (false);
}
