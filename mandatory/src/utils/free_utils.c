/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehedeman <ehedeman@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 12:54:57 by ehedeman          #+#    #+#             */
/*   Updated: 2025/01/08 12:56:02 by ehedeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	ft_free_coords(t_game *game, int mode)
{
	int	i;

	i = 0;
	if (game->map.coords)
	{
		while (game->map.coords[i])
		{
			if (game->map.coords[i])
				free(game->map.coords[i]);
			i++;
		}
	}
	if (game->map.coords)
		free(game->map.coords);
	if (game->map.content)
		free(game->map.content);
	game->map.content = NULL;
	game->map.coords = NULL;
	return (mode);
}
