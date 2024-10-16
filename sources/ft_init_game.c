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
	game->mlx = mlx_init();
	if (!game->mlx)
		print_error("Error\nGame allocation failed.\n", game, 1);
	game->mlx_window = mlx_new_window(game->mlx, game->win_width, \
		game->win_height, "cub3D");
	if (!game->mlx_window)
		print_error("Error\nGame allocation failed.\n", game, 1);
	if (mlx_hook(game->mlx_window, 2, 1L << 0, key_handler, game) == 0)
		print_error("Error\nGame allocation failed\n", game, 1);
	if (mlx_hook(game->mlx_window, 17, 1L << 0, close_window, game) == 0)
		print_error("Error\nGame allocation failed\n", game, 1);
	return (0);
}