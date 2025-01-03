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
	free(game->args.north);
	free(game->args.south);
	free(game->args.east);
	free(game->args.west);
	free(game->args.exit);
	if (game->mlx.window)
		mlx_destroy_window(game->mlx.init, game->mlx.window);
	if (game->mlx.init)
		free(game->mlx.init);
	return (0);
}
