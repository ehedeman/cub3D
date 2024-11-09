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

int	ft_free_map(t_game *game, int mode)
{
	int	i;

	i = 0;
	if (game->map.coordinates)
	{
		while (game->map.coordinates[i])
		{
			if (game->map.coordinates[i])
				free(game->map.coordinates[i]);
			i++;
		}
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
	free(game->args.north);
	free(game->args.south);
	free(game->args.east);
	free(game->args.west);
	if (game->mlx.window)
		mlx_destroy_window(game->mlx.init, game->mlx.window);
	if (game->mlx.init)
		free(game->mlx.init);
	return (0);
}
