/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehedeman <ehedeman@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:41:29 by ehedeman          #+#    #+#             */
/*   Updated: 2024/11/06 15:17:12 by ehedeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

static void	ft_set_vars(t_map *map, int y, int i)
{
	int	j;
	int	x;

	j = 0;
	x = 0;
	while (j++ < map->width - 2)
	{
		map->coordinates[y][x] = map->coords[i][j].type;
		// map->coordinates[y][x].x = x;
		// map->coordinates[y][x].y = y;
		// map->coordinates[y][x].type = map->coords[i][j].type;
		x++;
	}
	// map->coordinates[y][x].x = x + 1;
	// map->coordinates[y][x].y = y + 1;
	map->coordinates[y][x] = '\0';
}

static	void ft_free_coords(t_map *map)
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
	printf("Old map width and height (y | x): %i, %i\n", map->length, map->width);
	map->coordinates = malloc(sizeof(char *) * map->length - 2);
	if (!map->coordinates)
		print_error("Error: Failed to allocate cooordinates array.\n", game, 1);
	while (i++ < map->length - 3)
	{
		map->coordinates[y] = malloc(sizeof(char) * map->width - 1);
		if (!map->coordinates[y])
			print_error("Error: Failed to allocate cooordinates array.\n", game, 1);
		 ft_set_vars(map, y, i);
		y++;
	}
	map->coordinates[y] = NULL;
	ft_free_coords(map);
	map->width = map->width - 1;	//length including the '\n' at the end
	map->length = map->length - 2; //allocated rows minus the top and bottom row from coords
	printf("New Map Width and height (y | x): %i, %i\n", map->length, map->width);
}
