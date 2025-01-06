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

int	ft_free_map(t_game *game, int mode)
{
	int	i;

	i = 0;
	if (game->map.map)
	{
		while (game->map.map[i])
		{
			if (game->map.map[i])
				free(game->map.map[i]);
			i++;
		}
	}
	if (game->map.map)
		free(game->map.map);
	free(game->map.content);
	game->map.content = NULL;
	game->map.map = NULL;
	return (mode);
}

int	ft_free_game(t_game *game)
{
	free(game->args.exit);
	free(game->args.north);
	free(game->args.south);
	free(game->args.east);
	free(game->args.west);
	mlx_destroy_image(game->mlx.init, game->walls.north->img);
	mlx_destroy_image(game->mlx.init, game->walls.east->img);
	mlx_destroy_image(game->mlx.init, game->walls.west->img);
	mlx_destroy_image(game->mlx.init, game->walls.south->img);
	mlx_destroy_image(game->mlx.init, game->walls.exit->img);
	free(game->walls.east);
	free(game->walls.north);
	free(game->walls.west);
	free(game->walls.south);
	free(game->walls.exit);
	mlx_destroy_image(game->mlx.init, game->img);
	mlx_destroy_window(game->mlx.init, game->mlx.window);
	free(game->mlx.init);
	free(game);
	return (0);
	return (0);
}
