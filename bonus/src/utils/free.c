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
	if (game->map.content)
		free(game->map.content);
	game->map.content = NULL;
	game->map.map = NULL;
	return (mode);
}

void	free_args(t_game *game)
{
	if (game->args.north)
		free(game->args.north);
	if (game->args.south)
		free(game->args.south);
	if (game->args.west)
		free(game->args.west);
	if (game->args.east)
		free(game->args.east);
	if (game->args.exit)
		free(game->args.exit);
}

static void	free_walls_north_south(t_game *game)
{
	if (game->walls.north)
	{
		if (game->walls.north->img)
			mlx_destroy_image(game->mlx.init, game->walls.north->img);
		free(game->walls.north);
	}
	if (game->walls.south)
	{
		if (game->walls.south->img)
			mlx_destroy_image(game->mlx.init, game->walls.south->img);
		free(game->walls.south);
	}
}

void	free_walls(t_game *game)
{
	if (game->walls.east)
	{
		if (game->walls.east->img)
			mlx_destroy_image(game->mlx.init, game->walls.east->img);
		free(game->walls.east);
	}
	if (game->walls.west)
	{
		if (game->walls.west->img)
			mlx_destroy_image(game->mlx.init, game->walls.west->img);
		free(game->walls.west);
	}
	if (game->walls.exit)
	{
		if (game->walls.exit->img)
			mlx_destroy_image(game->mlx.init, game->walls.exit->img);
		free(game->walls.exit);
	}
	free_walls_north_south(game);
}

int	ft_free_game(t_game *game)
{
	free_walls(game);
	free_args(game);
	if (game->img)
		mlx_destroy_image(game->mlx.init, game->img);
	if (game->mlx.window)
		mlx_destroy_window(game->mlx.init, game->mlx.window);
	if (game->mlx.init)
	{
		mlx_destroy_display(game->mlx.init);
		free(game->mlx.init);
	}
	free(game);
	return (0);
}
