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

static void	ft_set_null(t_coordinates **new, t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map.length)
	{
		new[i] = NULL;
		i++;
	}
}

static void	ft_count_rows(t_game *game, int *i, int *count)
{
	while (game->map.content[*i])
	{
		if (game->map.content[*i] == '\n')
			*count += 1;
		*i += 1;
	}
	*count += 1;
}

t_coordinates	**ft_allocate_coords(t_game *game, int i)
{
	t_coordinates	**new;
	int				count;

	count = 0;
	ft_count_rows(game, &i, &count);
	new = malloc(sizeof(t_coordinates *) * (count + 3));
	if (!new)
		return (NULL);
	game->map.length = count + 3;
	game->map.length = count + 3;
	ft_set_null(new, game);
	return (new);
}

int	ft_allocate_map_rows(t_game *game)
{
	int	j;

	j = 0;
	game->map.coords[j] = malloc(sizeof(t_coordinates) * \
		(game->map.width + 2));
	j++;
	while (j < game->map.length - 1)
	{
		game->map.coords[j] = malloc(sizeof(t_coordinates) * \
			(game->map.width + 3));
		if (!game->map.coords[j])
			return (1);
		j++;
	}
	return (0);
}
