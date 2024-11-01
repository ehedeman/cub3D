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

int	close_window(t_game *game)
{
	print_error("Window closed\n", game, 0);
	exit(0);
	return (0);
}

void	ft_set_current_orientation(t_player *player)
{
	if (player->start_orientation == 'N')
		player->current_orientation = NO;
	if (player->start_orientation == 'S')
		player->current_orientation = SO;
	if (player->start_orientation == 'E')
		player->current_orientation = EA;
	if (player->start_orientation == 'W')
		player->current_orientation = WE;
}

void	ft_set_player_location(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (i++ < game->map.allocated_rows - 1)
	{
		j = -1;
		while (j++ < game->map.map_length)
		{
			if (game->map.coords[i][j].type == 'N' \
				|| game->map.coords[i][j].type == 'S' \
					|| game->map.coords[i][j].type == 'W' \
						|| game->map.coords[i][j].type == 'E')
			{
				game->player.current = &game->map.coords[i][j];
				game->player.start_orientation = game->player.current->type;
				ft_set_current_orientation(&game->player);
				printf("Player Location: (%i|%i), %c, %i\n", \
					game->player.current->x, game->player.current->y, \
						game->player.start_orientation, \
							game->player.current_orientation);
				return ;
			}
		}
	}
}

void ft_init_window(t_game *game);

int	ft_init_game(t_game *game)
{
	ft_set_player_location(game);
	ft_init_window(game);	 
	mlx_hook(game->mlx.mlx_window, EVENT_DESTROY, 1L<<0, close_window, game);
	// mlx_hook(game->mlx.mlx_window, EVENT_KEY_PRESS, 1L<<0, key_press, game);
	// mlx_hook(game->mlx.mlx_window, EVENT_KEY_RELEASE, 1L<<1, key_release, game);
	// mlx_loop_hook(game->mlx.mlx, draw_loop, game);
	mlx_loop(game->mlx.mlx);
	return (0);
}

void ft_init_window(t_game *game)
{
	game->mlx.mlx = mlx_init();
	if (!game->mlx.mlx)
		print_error("Error\nGame allocation failed.\n", game, 1);
	game->mlx.mlx_window = mlx_new_window(game->mlx.mlx, SCREEN_W, SCREEN_H, "cub3D");
	if (!game->mlx.mlx_window)
		print_error("Error\nGame allocation failed.\n", game, 1);
	game->mlx.img = mlx_new_image(game->mlx.mlx, SCREEN_W, SCREEN_H);
	if (!game->mlx.img)
		print_error("Error\nGame allocation failed.\n", game, 1);
}

void draw_loop(t_game *game)
{
	(void)game;
}



/* int	ft_init_game(t_game *game)
{
	ft_set_player_location(game);
	game->mlx.mlx = mlx_init();
	if (!game->mlx.mlx)
		print_error("Error\nGame allocation failed.\n", game, 1);
	game->mlx.mlx_window = mlx_new_window(game->mlx.mlx, game->mlx.win_width, \
		game->mlx.win_height, "cub3D");
	if (!game->mlx.mlx_window)
		print_error("Error\nGame allocation failed.\n", game, 1);
	if (mlx_hook(game->mlx.mlx_window, 17, 1L << 0, close_window, game) == 0)
		print_error("Error\nGame allocation failed\n", game, 1);
	if (mlx_key_hook(game->mlx.mlx_window, key_handler, game) == 0)
		print_error("Error\nGame allocation failed\n", game, 1);
	if (mlx_hook(game->mlx.mlx_window, 2, 1L << 0, key_handler, game) == 0)
		print_error("Error\nGame allocation failed\n", game, 1);
	if (mlx_hook(game->mlx.mlx_window, 17, 1L << 0, close_window, game) == 0)
		print_error("Error\nGame allocation failed\n", game, 1);
	int height = WALL_HEIGHT;
	int width = WALL_WIDTH;
	game->mlx.test = mlx_xpm_file_to_image(game->mlx.mlx, WALL_XPM,
			&width, &height);
	if (!game->mlx.test)
		print_error("Error\nImage allocation failed.\n", game, 1);
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.mlx_window, \
			game->mlx.test, 200, 200); 
	return (0);
} */

	// for testing of images and shit
	// int	height;
	// int	width;

	// height = WALL_HEIGHT;
	// width = WALL_WIDTH;
	// game->mlx.test = mlx_xpm_file_to_image(game->mlx.mlx, WALL_XPM,
	// 		&width, &height);
	// if (!game->mlx.test)
	// 	print_error("Error\nImage allocation failed.\n", game, 1);
	// mlx_put_image_to_window(game->mlx.mlx, game->mlx.mlx_window, \
	// 		game->mlx.test, 1200, 800);