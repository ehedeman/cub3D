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

// coords[i][j] -> i == y and j == x cuz i keep forgetting that
static void ft_set_map_coords(t_game *game, int *i, int *x, int *y)
{
	while (game->map.content[*i] && game->map.content[*i] != '\n')	//save until \n, then y + 1
	{
		if (ft_is_map_char(game->map.content[*i]))					//if not a map_char then save as - (so e.g if its whitespace)
			game->map.coords[*y][*x].type = '-';					// y and x do not need to be -1 because its still part of the map, just not accessible
		else
			game->map.coords[*y][*x].type = game->map.content[*i];
		game->map.coords[*y][*x].x = *x - 1;							// x and y get set no matter what
		game->map.coords[*y][*x].y = (game->map.allocated_rows - 3) - *y;
		*i += 1;
		*x += 1;
	}
}

static int	ft_skip_til_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = i;
	while (game->map.content[i])
	{
		while (game->map.content[i] && ft_is_whitespace(game->map.content[i]))		//skip whitespace
			i++;
		if (game->map.content[i])
		{
			while (game->map.content[i] && game->map.content[i] != '\n')			//skip until newline (map is never first)
				i++;
			if (!game->map.content[i])
				return (0);
		}
		else
			return (0);
		if (game->map.content[i] && game->map.content[i] == '\n')
		{
			i++;																	//skip newline
			j = i;
			while (game->map.content[i]	&& ft_is_whitespace(game->map.content[i]))	//skip possible whitespace
				i++;
			if (game->map.content[i] && game->map.content[i] == '1')				//if the first symbol after newline is 1
				return (j);
		}
	}
	return (j);
}
// works under the assumption that the map is the last part with no more new lines etc
// (if there's whitespace after the map it'll, so an empty line after, the program wont
//	recognize it as the last line and will not save the bottom row of empty space.)

static void	ft_set_map_barriers(t_game *game, int i, int y)
{
	int x;

	while (game->map.content[i])
	{
		x = 0;
		if (y + 1 == game->map.allocated_rows - 2)
			ft_set_map_barrier(game, &game->map.content[i], y + 1);
		ft_set_map_side_barrier(game, &x, &y);
		ft_set_map_coords(game, &i, &x, &y);
		while (x < game->map.map_length)
			ft_set_map_side_barrier(game, &x, &y);
		game->map.coords[y][x].type = '\n';
		y++;
		if (game->map.content[i])
			i++;
	}
}

//dont touch, this took forever
static void ft_set_map_values(t_game *game, t_coordinates **coords)
{
	game->map.top_l = &coords[1][1];					//1|1 because 0|0 is the negative space around map
	game->map.top_r = &coords[1][game->map.map_length - 2];
	game->map.bottom_l = &coords[game->map.allocated_rows - 3][1];
	game->map.bottom_r = &coords[game->map.allocated_rows - 3][game->map.map_length - 2];
	game->map.point_zero = game->map.bottom_l;			//0|0 on coordinates
}

int	ft_save_map(t_game *game)
{
	int	i;
	int	y;

	y = 0;
	i = ft_skip_til_map(game);
	if (!i)
		return (1);
	ft_find_longest_row(game, &game->map.content[i]);
	game->map.coords = ft_allocate_coords(game, i);		//allocates the coords array
	if (!game->map.coords)
		return (ft_free_map(game, 1));
	if (ft_allocate_map_rows(game))						//allocates the rows for coords array
		return (ft_free_map(game, 1));
	ft_set_map_barrier(game, &game->map.content[i], y);		//sets top barrier
	y++;
	ft_set_map_barriers(game, i, y);
	game->map.coords[game->map.allocated_rows - 1] = NULL;
	ft_set_map_values(game, game->map.coords);
	return (0);
}
