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

static void	ft_set_vars(t_map *map, int y, int i)
{
	int	j;
	int	x;

	j = 0;
	x = 0;
	while (j++ < map->width - 2)
	{
		map->map[y][x] = map->coords[i][j].type;
		x++;
	}
	map->map[y][x] = '\0';
}

static	void	ft_free_coords(t_map *map)
{
	int	i;

	i = 0;
	while (i <= map->length - 1)
	{
		if (map->coords[i])
			free(map->coords[i]);
		i++;
	}
	if (map->coords)
		free(map->coords);
	map->coords = NULL;
}

void	ft_convert_map(t_game *game, t_map *map, int i)
{
	int	y;

	y = 0;
	map->map = malloc(sizeof(char *) * map->length - 2);
	if (!map->map)
		print_error("Error: Failed to allocate array.\n", game, 1);
	while (i++ < map->length - 3)
	{
		map->map[y] = malloc(sizeof(char) * map->width - 1);
		if (!map->map[y])
			print_error("Error: Failed to allocate array.\n", game, 1);
		ft_set_vars(map, y, i);
		y++;
	}
	map->map[y] = NULL;
	ft_free_coords(map);
	map->width = map->width - 1;
	map->length = map->length - 2;
}
