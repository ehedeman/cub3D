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

static int	ft_skip_til_map_start(t_game *game, int *i)
{
	while (game->map.content[*i] && ft_is_whitespace(game->map.content[*i]))
		*i += 1;
	if (game->map.content[*i])
	{
		while (game->map.content[*i] && game->map.content[*i] != '\n')
			*i += 1;
		if (!game->map.content[*i])
			return (0);
	}
	else
		return (0);
	return (1);
}

static int	ft_skip_til_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = i;
	while (game->map.content[i])
	{
		if (!ft_skip_til_map_start(game, &i))
			return (0);
		if (game->map.content[i] && game->map.content[i] == '\n')
		{
			i++;
			j = i;
			while (game->map.content[i] \
				&& ft_is_whitespace(game->map.content[i]))
				i++;
			if (game->map.content[i] && game->map.content[i] == '1')
				return (j);
		}
	}
	return (j);
}

/*
	works under the assumption that the map is the last part with no 
	more new lines etc.

->	if there's whitespace after the map the program wont recognize
	it as the last line and will not save the bottom row of empty space.
*/

static void	ft_set_map_barriers(t_game *game, int i, int y)
{
	int	x;

	while (game->map.content[i])
	{
		x = 0;
		if (y + 1 == game->map.length - 2)
			ft_set_map_barrier(game, &game->map.content[i], y + 1);
		ft_set_map_side_barrier(game, &x, &y);
		ft_set_map_coords(game, &i, &x, &y);
		while (x < game->map.width)
			ft_set_map_side_barrier(game, &x, &y);
		game->map.coords[y][x].type = '\n';
		y++;
		if (game->map.content[i])
			i++;
	}
}

int	ft_save_map(t_game *game)
{
	int	i;
	int	y;

	y = 0;
	i = ft_skip_til_map(game);
	if (!i)
		print_error("Error\nProcessing the map.\n", game, 1);
	ft_find_longest_row(game, &game->map.content[i]);
	game->map.coords = ft_allocate_coords(game, i);
	if (!game->map.coords)
		print_error("Error\nAllocating memory for the map.\n", game, 1);
	if (ft_allocate_map_rows(game))
		print_error("Error\nAllocating memory for the map.\n", game, 1);
	ft_set_map_barrier(game, &game->map.content[i], y);
	y++;
	ft_set_map_barriers(game, i, y);
	game->map.coords[game->map.length - 1] = NULL;
	return (0);
}

/*
	the map is saved in a rectanuglar format with a barrier of negative 
	space around it basically. that negative space has coordinates as well 
	because thats easier. the coordinates start from -1 in the bottom left
	corner and go up to whatever in the top right corner.
	the 'type' variable is set as whatever the symbol is on the map, except
	for whitespace, thats saved as '-'.
	variables bottom_l etc are for naviating the map more easily so you dont
	have to think about where the barrier starts and stuff

	the negative space thats inbetween walls and stuff is part of the map 
*/
