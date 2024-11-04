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
	return (0);
}

// void	ft_set_current_orientation(t_player *player)
// {
// 	if (player->start_orientation == 'N')
// 		player->current_orientation = NO;
// 	if (player->start_orientation == 'S')
// 		player->current_orientation = SO;
// 	if (player->start_orientation == 'E')
// 		player->current_orientation = EA;
// 	if (player->start_orientation == 'W')
// 		player->current_orientation = WE;
// }

// void	ft_set_player_location(t_game *game, t_map *map)
// {
// 	int i = 0;
// 	int j = 0;
// 	while (i < map->length - 2)
// 	{
// 		j = 0;
// 		while (j < map->width)
// 		{
// 			if (map->coordinates[i][j].type == 'N' \
// 				|| map->coordinates[i][j].type == 'S' \
// 					|| map->coordinates[i][j].type == 'W' \
// 						|| map->coordinates[i][j].type == 'E')
// 			{
// 				game->player.current = &map->coordinates[i][j];
// 				game->player.start_orientation = game->player.current->type;
// 				ft_set_current_orientation(&game->player);
// 				printf("Player Location: (%f|%f), %c, %i\n", \
// 					game->player.current->x, game->player.current->y, \
// 						game->player.start_orientation, \
// 							game->player.current_orientation);
// 				return ;
// 			}
// 			j++;
// 		}
// 		i++;
// 	}
// }

// int	ft_init_game(t_game *game)
// {
// 	ft_set_player_location(game, &game->map);
// 	game->mlx.mlx = mlx_init();
// 	if (!game->mlx.mlx)
// 		print_error("Error\nGame allocation failed.\n", game, 1);
// 	game->mlx.mlx_window = mlx_new_window(game->mlx.mlx, game->mlx.win_width, \
// 		game->mlx.win_height, "cub3D");
// 	if (!game->mlx.mlx_window)
// 		print_error("Error\nGame allocation failed.\n", game, 1);
// 	if (mlx_hook(game->mlx.mlx_window, 2, 1L << 0, key_handler, game) == 0)
// 		print_error("Error\nGame allocation failed\n", game, 1);
// 	if (mlx_hook(game->mlx.mlx_window, 17, 1L << 0, close_window, game) == 0)
// 		print_error("Error\nGame allocation failed\n", game, 1);
// 	return (0);
// }
