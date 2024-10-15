/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c		                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ****** <******@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 12:33:17 by ******           #+#    #+#              */
/*   Updated: 2024/10/11 13:09:41 by ******           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	ft_set_map_side_barrier(t_game *game, int *x, int *y)
{
	game->map.coords[*y][*x].type = '-';	//to create a barrier around the whole map for checking if its valid
	game->map.coords[*y][*x].x = -1;
	game->map.coords[*y][*x].y = -1;
	*x += 1;
}

void	ft_set_map_barrier(t_game *game, char *map, int y)
{
	int	x;

	x = 0;
	game->map.coords[y][x].type = '-';	//x needs to be two more than the map is wide
	game->map.coords[y][x].x = -1;
	game->map.coords[y][x].y = -1;
	x++;
	while (x < game->map.map_length)
	{
		game->map.coords[y][x].type = '-';
		game->map.coords[y][x].x = -1;
		game->map.coords[y][x].y = -1;
		x++;
		map++;
	}
	game->map.coords[y][x].type = '-';	//x needs to be two more than the map is wide
	game->map.coords[y][x].x = -1;
	game->map.coords[y][x].y = -1;
	game->map.coords[y][x + 1].type = '\n';
	game->map.coords[y][x + 1].x = -1;
	game->map.coords[y][x + 1].y = -1;
}

void	ft_find_longest_row(t_game *game, char *map)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (map[i])
	{
		if (map[i] == '\n')
		{
			if (count < j)
				count = j; //no plus one for newlie because newline is at end anyways
			j = 0;
			i++;
			continue ;
		}
		j++;
		i++;
	}
	if (count < j)
		count = j;	//in case the last line is the longest of the map
	game->map.map_length = count + 2; // plus two because side barriers need to be included
}
