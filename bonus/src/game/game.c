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

static int	ft_close_window(t_game *game)
{
	print_error("Window closed\nThanks for playing\n", game, 0);
	return (0);
}

void	ft_set_null(t_game *game)
{
	game->args.north = NULL;
	game->args.south = NULL;
	game->args.east = NULL;
	game->args.west = NULL;
	game->args.exit = NULL;
	game->walls.north = NULL;
	game->walls.south = NULL;
	game->walls.east = NULL;
	game->walls.west = NULL;
	game->walls.exit = NULL;
	game->img = NULL;
	game->mlx.window = NULL;
	game->mlx.init = NULL;
	game->map.content = NULL;
	game->map.coords = NULL;
	game->map.map = NULL;
	game->args.ceiling.r = -1;
	game->args.ceiling.g = -1;
	game->args.ceiling.b = -1;
	game->args.floor.r = -1;
	game->args.floor.g = -1;
	game->args.floor.b = -1;
}

void	ft_game(char *map_path)
{
	t_game	*game;

	game = ft_calloc(1, sizeof(t_game));
	if (!game)
		ft_err_exit("Failed to allocate memory for game\n");
	ft_set_null(game);
	game->map.file_name = map_path;
	ft_init_game(game);
	mlx_hook(game->mlx.window, KeyPress, KeyPressMask, ft_key_press, game);
	mlx_hook(game->mlx.window, KeyRelease, KeyReleaseMask, \
		ft_key_release, &game->player);
	mlx_loop_hook(game->mlx.init, draw_loop, game);
	mlx_hook(game->mlx.window, DestroyNotify, 0, ft_close_window, game);
	mlx_loop(game->mlx.init);
}
