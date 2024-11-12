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

static void	ft_init_mlx(t_game *game);
// static void	ft_init_bg(t_game *game);

void	ft_init_game(t_game *game)
{
	ft_map_parsing(game->map.content, game);
	ft_convert_map(game, &game->map, 0);
	init_player(&game->player, &game->map);
	ft_init_mlx(game);
	// ft_init_bg(game);
}

static void	ft_init_mlx(t_game *game)
{
	game->mlx.init = mlx_init();
	if (!game->mlx.init)
		ft_err_game("Failed to initialize mlx\n", game);
	game->mlx.window = mlx_new_window(game->mlx.init, WIDTH, HEIGHT, "cub3D");
	if (!game->mlx.window)
		ft_err_game("Failed to create mlx window\n", game);
	game->img = mlx_new_image(game->mlx.init, WIDTH, HEIGHT);
	game->data = mlx_get_data_addr(game->img, &game->bpp, &game->size_line, &game->endian);
	mlx_put_image_to_window(game->mlx.init, game->mlx.window, game->img, 0, 0);
}

// static void	ft_init_bg(t_game *game)
// {
// 	game->walls.background = malloc(sizeof(t_img));
// 	if (!game->walls.background)
// 		ft_err_game("Failed to allocate memory for background", game);
// 	game->walls.background->img = mlx_new_image(game->mlx.init, WIDTH, HEIGHT);
// 	if (!game->walls.background->img)
// 		ft_err_game("Failed to create background image", game);
// 	game->walls.background->addr = mlx_get_data_addr(game->walls.background->img,
// 			&game->walls.background->bpp, &game->walls.background->ll,
// 			&game->walls.background->endian);
// 	if (!game->walls.background->addr)
// 		ft_err_game("Failed to get background image address", game);
// }
