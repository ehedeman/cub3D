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

int	ft_free_map(t_game *game, int mode)
{
	int	i;

	i = 0;
	while (i <= game->map.allocated_rows - 1)
	{
		if (game->map.coords[i])		//should work because its set to NULL unless allocated
			free(game->map.coords[i]);
		i++;
	}
	if (game->map.coords)
		free(game->map.coords);
	free(game->map.content);
	game->map.coords = NULL;
	game->map.content = NULL;	//so it cant be freed again
	return (mode);							//1 for the error_return, 0 for normal free so function can be used elsewhere
}

int	ft_free_game(t_game *game)
{
	if (game->player.mlx)
		free(game->player.mlx);
	// if (game->mlx_window)
	// 	free(game->mlx_window);	//if window is closed thru ESC or x then this aint nessecary
								//for some reason. have to look into mlx_loop and stuff again i guess
	if (game->mlx.mlx)
		free(game->mlx.mlx);
	return (0);
}