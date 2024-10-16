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

//everything set to zero or some other value for freeing purposes and stuff
void	ft_set_zero(t_game *game)
{
	game->map.content = NULL;
	game->map.coords = NULL;
	game->map.map_length = 0;
	game->map.top_l = NULL;
	game->map.top_r = NULL;
	game->map.bottom_l = NULL;
	game->map.bottom_r = NULL;
	game->map.point_zero = NULL;
	game->map.player_start = NULL;
	game->walls.north = NULL;
	game->walls.south = NULL;
	game->walls.east = NULL;
	game->walls.west = NULL;
	game->player.current = NULL;
	game->player.next = NULL;
	game->player.mlx = NULL;
	game->player.current_orientation = '\0';
	game->mlx = NULL;
	game->mlx_window = NULL;
	game->win_height = 2000;
	game->win_width = 3000;
	game->game_end = 0;
}