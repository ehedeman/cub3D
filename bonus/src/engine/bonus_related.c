/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_related.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehedeman <ehedeman@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 14:19:06 by ehedeman          #+#    #+#             */
/*   Updated: 2025/01/08 13:13:07 by ehedeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

bool	t_exit(float px, float py, t_map *map)
{
	int	x;
	int	y;

	y = py / BLOCK;
	x = px / BLOCK;
	if (x <= 0 || x >= map->width - 2 || y <= 0 || y >= map->length - 2)
		return (false);
	if (map->map[y][x] == 'F')
		return (true);
	return (false);
}
