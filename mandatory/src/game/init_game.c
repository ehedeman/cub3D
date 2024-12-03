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

static void	ft_init_mlx(t_game *game);
static void	init_walls(t_game *game);
static void	init_tex(t_game *game, t_img **texture, char *path_texture);
static void init_colors(t_game *game);

void	ft_init_game(t_game *game)
{
	ft_map_parsing(game->map.content, game);
	ft_convert_map(game, &game->map, 0);
	init_player(&game->player, &game->map);
	ft_init_mlx(game);
	init_walls(game);
	init_colors(game);
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

static void	init_walls(t_game *game)
{
	init_tex(game, &game->tex.north, game->args.north);
	init_tex(game, &game->tex.south, game->args.south);
	init_tex(game, &game->tex.east, game->args.east);
	init_tex(game, &game->tex.west, game->args.west);
}

static void	init_tex(t_game *game, t_img **texture, char *path_texture)
{
	int w;
	int h;
	*texture = malloc(sizeof(t_img));
	if (!*texture)
		ft_err_game("Failed to allocate memory for texture", game);
	(*texture)->img = mlx_xpm_file_to_image(game->mlx.init, path_texture, &w, &h);
	if (!(*texture)->img)
		ft_err_game("Failed to load texture", game);
	(*texture)->addr = mlx_get_data_addr((*texture)->img, &(*texture)->bpp, &(*texture)->ll, &(*texture)->endian);
	if (!(*texture)->addr)
		ft_err_game("Failed to get texture address", game);
	(*texture)->width = w;
	(*texture)->height = h;
	//experiemtnal
	(*texture)->t_step.y = 0;
	(*texture)->pos.y = 0;
}

// void get_color(t_game *game, int *colors, t_rgb color);

static void init_colors(t_game *game)
{
	// get_color(game, &game->args.floor, game->args.floor);
	// get_color(game, &game->args.ceiling, game->args.ceiling);
	game->tex.floor = (game->args.floor.r << 16 | game->args.floor.g << 8 | game->args.floor.b);
	game->tex.ceiling = (game->args.ceiling.r << 16 | game->args.ceiling.g << 8 | game->args.ceiling.b);
	// printf("floor: %d\n", game->tex.floor);
	// printf("ceiling: %d\n", game->tex.ceiling);
}
