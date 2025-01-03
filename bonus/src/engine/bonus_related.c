/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_related.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehedeman <ehedeman@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 14:19:06 by ehedeman          #+#    #+#             */
/*   Updated: 2025/01/03 15:02:47 by ehedeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

bool	t_exit(float px, float py, char **map)
{
	int	x;
	int	y;

	y = py / BLOCK;
	x = px / BLOCK;
	if (map[y][x] == 'F')
		return (true);
	return (false);
}
