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

void	init_mlx(t_mlx *mlx)
{
	mlx->mlx = NULL;
	mlx->mlx_window = NULL;
	mlx->win_height = 1000;
	mlx->win_width = 2000;
}

void	init_map(t_map *map)
{
	map->content = NULL;
	map->coords = NULL;
	map->coordinates = NULL;
	map->width = 0;
	map->length = 0;
}
void	init_walls(t_wall *walls)
{
	walls->north = NULL;
	walls->south = NULL;
	walls->east = NULL;
	walls->west = NULL;
}

// void	init_player(t_player *player)
// {
// 	player->current = NULL;
// 	player->next = NULL;
// 	player->current_orientation = '\0';
// }

void	init(t_game *game)
{
	init_mlx(&game->mlx);
	init_map(&game->map);
	init_walls(&game->walls);
//	init_player(&game->player);
	game->game_end = 0;
}
