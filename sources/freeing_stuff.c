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

int	ft_free_map(t_game *game, int mode)
{
	int	i;

	i = 0;
	while (i < game->map.length)
	{
		if (game->map.coordinates[i])
			free(game->map.coordinates[i]);
		i++;
	}
	if (game->map.coordinates)
		free(game->map.coordinates);
	free(game->map.content);
	game->map.content = NULL;
	game->map.coordinates = NULL;
	return (mode);
}
// mode = 1 for the error_return, 0 for normal free so
// function can be used elsewhere

int	ft_free_game(t_game *game)
{
	free(game->walls.north);
	free(game->walls.south);
	free(game->walls.east);
	free(game->walls.west);
	if (game->mlx.mlx_window)
		mlx_destroy_window(game->mlx.mlx, game->mlx.mlx_window);
	if (game->mlx.mlx)
		free(game->mlx.mlx);
	return (0);
}
