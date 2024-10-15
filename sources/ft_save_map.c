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

static int ft_is_map_char(char c)
{
	if (c == '1' || c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (0);
	return (1);
}

static void ft_set_map_coords(t_game *game, int *i, int *x, int *y)
{
	while (game->map.content[*i] && game->map.content[*i] != '\n')	//save until \n, then y + 1
	{
		if (ft_is_map_char(game->map.content[*i]))					//if not a map_char then save as - (so e.g if its whitespace)
			game->map.coords[*y][*x].type = '-';					// y and x do not need to be -1 because its still part of the map,,just not accessible
		else
			game->map.coords[*y][*x].type = game->map.content[*i];
		game->map.coords[*y][*x].x = *x;							// x and y get set no matter what
		game->map.coords[*y][*x].y = *y;
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
		while (game->map.content[i] && ft_is_whitespace(game->map.content[i]))	//skip whitespace
			i++;
		if (game->map.content[i])
		{
			while (game->map.content[i] && game->map.content[i] != '\n')	//skip until newline (map is never first)
				i++;
		}
		else
			return (0);
		if (game->map.content[i] && game->map.content[i] == '\n')
		{
			j = i;
			i++;														//skip newline
			while (game->map.content[i]	&& ft_is_whitespace(game->map.content[i]))	//skip possible whitespace
				i++;
			if (game->map.content[i] && game->map.content[i] == '1')		//if the first symbol after newline is 1
				return (j);
		}
	}
	return (j);
}
// works under the assumption that the map is the last part with no more new lines etc
// (if there's whitespace after the map it'll, so an empty line after, the program wont
//	recognize it as the last line and will not save the bottom row of empty space.)

int	ft_save_map(t_game *game, int x, int y)
{
	int	i;

	i = ft_skip_til_map(game);
	if (!i)
		return (1);
	game->map.coords = ft_allocate_coords(game, i);
	if (!game->map.coords)
		return (1);
	if (ft_allocate_map_rows(game, i))
		return (ft_free_map(game, 1));
	ft_set_map_barrier(game->map.coords, &game->map.content[i], y);		//sets top barrier
	y++;
	while (game->map.content[i])
	{
		x = 0;
		if (y + 1 == game->map.allocated_rows - 2)
			ft_set_map_barrier(game->map.coords, &game->map.content[i], y + 1);
		ft_set_map_side_barrier(game, &x, &y);
		ft_set_map_coords(game, &i, &x, &y);
		ft_set_map_side_barrier(game, &x, &y);
		game->map.coords[y][x].type = '\n';
		y++;
		if (game->map.content[i])
			i++;
	}
	game->map.coords[game->map.allocated_rows - 1] = NULL;
	return (0);
}
