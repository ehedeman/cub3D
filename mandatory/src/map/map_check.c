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

#include "../includes/cub3D.h"

static void	ft_check_coords(t_game *game, t_coordinates **coords, int i, int j)
{
	if (i != 0)
	{
		if (coords[i - 1][j].type != '-' && coords[i - 1][j].type != '1'\
			&& coords[i - 1][j].type != '\n')
			print_error("Error\nWall error\n", game, 1);
	}
	if (i < game->map.length - 2)
	{
		if (coords[i + 1][j].type != '-' && coords[i + 1][j].type != '1'\
			&& coords[i + 1][j].type != '\n')
			print_error("Error\nWall error\n", game, 1);
	}
	if (j != 0)
	{
		if (coords[i][j - 1].type != '-' && coords[i][j - 1].type != '1'\
			&& coords[i][j - 1].type != '\n')
			print_error("Error\nWall error\n", game, 1);
	}
	if (coords[i][j + 1].type != '-' && coords[i][j + 1].type != '1'\
		&& coords[i][j + 1].type != '\n')
		print_error("Error\nWall error\n", game, 1);
}

//check if map is surrounded by walls
static void	ft_check_map_walls(t_game *game, t_coordinates **coords)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map.length - 1)
	{
		j = 0;
		while (j < game->map.width)
		{
			if (coords[i][j].type == '-')
				ft_check_coords(game, coords, i, j);
			j++;
		}
		i++;
	}
}

static void	ft_check_player_symbol(t_game *game, t_coordinates **coords)
{
	int	i;
	int	j;
	int	player;

	i = 0;
	player = 0;
	while (i < game->map.length - 2)
	{
		j = -1;
		while (j++ < game->map.width)
		{
			if (coords[i][j].type == 'N' || coords[i][j].type == 'S'
				|| coords[i][j].type == 'E' || coords[i][j].type == 'W')
				player++;
		}
		i++;
	}
	if (player > 1)
		print_error("Error\nMap: multiple player locations.\n", game, 1);
	else if (player < 1)
		print_error("Error\nMap: missing player location.\n", game, 1);
}

static void	ft_check_wrong_symbols(t_game *game, t_coordinates **coords)
{
	int	i;
	int	j;

	i = -1;
	while (i++ < game->map.length - 2)
	{
		j = -1;
		while (j++ < game->map.width)
		{
			if (ft_is_map_char(coords[i][j].type) && coords[i][j].type != '-'
				&& coords[i][j].type != '\n')
				print_error("Error\nMap: unknown symbol.\n", game, 1);
		}
	}
}

void	ft_map_check(t_game *game)
{
	ft_check_map_walls(game, game->map.coords);
	ft_check_player_symbol(game, game->map.coords);
	ft_check_wrong_symbols(game, game->map.coords);
}
