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
int	key_handler(int key, t_game *game)
{
	if (key == XK_ESCAPE)
		print_error("Thanks for playing\n", game, 0);
	// if (game->game_end == 0)
	// {
	// 	printf("Key pressed: %i\n\n", key);
	// 	if ((key == 119 || key == 65362) && check_for_objects(game, 1) == 0)
	// 		move_player(game, 2, 0, 0);
	// 	if ((key == 115 || key == 65364) && check_for_objects(game, 2) == 0)
	// 		move_player(game, 1, 0, 0);
	// 	if ((key == 97 || key == 65361) && check_for_objects(game, 3) == 0)
	// 		move_player(game, 0, 2, 1);
	// 	if ((key == 100 || key == 65363) && check_for_objects(game, 4) == 0)
	// 		move_player(game, 0, 1, 2);
	// }
	return (0);
}