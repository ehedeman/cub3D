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

static void	ft_set_null(t_coordinates **new, t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map.allocated_rows)
	{
		new[i] = NULL;	//important for freeing in case of error
		i++;
	}
}

static void	ft_count_rows(t_game *game, int *i, int *count)
{
	while (game->map.content[*i])			//counts amount of rows
	{
		if (game->map.content[*i] == '\n')
			*count += 1;
		*i += 1;
	}
	*count += 1;							//because the last row doesnt have a newline -> might be wrong
}

t_coordinates	**ft_allocate_coords(t_game *game, int i)
{
	t_coordinates	**new;
	int				count;

	count = 0;												//always one more needed at the start and end
	ft_count_rows(game, &i, &count);
	new = malloc(sizeof(t_coordinates *) * (count + 3));	//+2 for the bottom and top row barrier +1 for NULL at end
	if (!new)
		return (NULL);
	game->map.allocated_rows = count + 3;					//last is NULL | could actually just set it to count + 2 to avoid accessing the null row
	ft_set_null(new, game);
	return (new);
}

int	ft_allocate_map_rows(t_game *game)
{
	int	j;

	j = 0;
	game->map.coords[j] = malloc(sizeof(t_coordinates) * (game->map.map_length + 2));
	j++;
	while (j < game->map.allocated_rows - 1)
	{
		game->map.coords[j] = malloc(sizeof(t_coordinates) * (game->map.map_length + 3));
		if (!game->map.coords[j])
			return (1);
		j++;
	}
	return (0);
}
