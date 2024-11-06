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

//stolen from my so_long
//W,A,S,D for moving, left and right arrow for changing orientation? ->N,S,W,E
// void	ft_check_movement_keys(int key, t_game *game, int direction)
// {
// 	if (key == W_KEY && !ft_check_for_walls(direction, \
// 		game->map.coords, &game->player))
// 		ft_change_current_location(&game->player, direction, game->map.coords);
// 	else if (key == A_KEY && !ft_check_for_walls(direction, \
// 		game->map.coords, &game->player))
// 		ft_change_current_location(&game->player, direction, game->map.coords);
// 	else if (key == S_KEY && !ft_check_for_walls(direction, \
// 		game->map.coords, &game->player))
// 		ft_change_current_location(&game->player, direction, game->map.coords);
// 	else if (key == D_KEY && !ft_check_for_walls(direction, \
// 		game->map.coords, &game->player))
// 		ft_change_current_location(&game->player, direction, game->map.coords);
// }

// int	key_handler(int key, t_game *game)
// {
// 	// int	direction;
// 	// if (game->game_end == 0)
// 	// {
// 	// 	direction = ft_check_direction(key, &game->player);
// 	// 	ft_check_movement_keys(key, game, direction);
// 	// 	if (key == LEFT_ARROW)
// 	// 		ft_change_current_orientation(key, &game->player);
// 	// 	else if (key == RIGHT_ARROW)
// 	// 		ft_change_current_orientation(key, &game->player);
// 	// }
// 	return (0);
// }
