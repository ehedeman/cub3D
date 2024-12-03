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

void ft_print_map(t_map *map)
{
	int	i = 0;
	int	j = 0;

	while (map->coordinates[i])
	{
		j = 0;
		while (map->coordinates[i][j])
		{
			printf("%c", map->coordinates[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	printf("%p\n", map->coordinates[i]);
}
