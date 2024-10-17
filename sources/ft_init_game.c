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

int close_window(t_game *game)
{
	print_error("Window closed\n", game, 0);
	return (0);
}

int	ft_init_game(t_game *game)
{
	int	height = 512, width = 512;
	game->mlx.mlx = mlx_init();
	if (!game->mlx.mlx)
		print_error("Error\nGame allocation failed.\n", game, 1);
	game->mlx.mlx_window = mlx_new_window(game->mlx.mlx, game->mlx.win_width, \
		game->mlx.win_height, "cub3D");
	if (!game->mlx.mlx_window)
		print_error("Error\nGame allocation failed.\n", game, 1);
	if (mlx_hook(game->mlx.mlx_window, 2, 1L << 0, key_handler, game) == 0)
		print_error("Error\nGame allocation failed\n", game, 1);
	if (mlx_hook(game->mlx.mlx_window, 17, 1L << 0, close_window, game) == 0)
		print_error("Error\nGame allocation failed\n", game, 1);
	
	game->mlx.test = mlx_xpm_file_to_image(game->mlx.mlx, WALL_XPM,
			&width, &height);										//as the name suggests, for testing
	if (!game->mlx.test)
		print_error("Error\nImage allocation failed.\n", game, 1);
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.mlx_window, \
			game->mlx.test, 1500, 1000);
	return (0);
}
