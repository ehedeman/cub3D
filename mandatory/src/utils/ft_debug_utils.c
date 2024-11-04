/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_debug_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalchuk <svalchuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 13:10:56 by svalchuk          #+#    #+#             */
/*   Updated: 2024/11/03 15:30:48 by svalchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	ft_print_params(t_game *game)
{
	printf(GREEN"\nNorth Wall: %s\n", game->walls.north);
	printf("South Wall: %s\n", game->walls.south);
	printf("East Wall: %s\n", game->walls.east);
	printf("West Wall: %s\n", game->walls.west);
	printf("Floor Color: %i %i %i\n", game->walls.floor.r, game->walls.floor.g, game->walls.floor.b);
	printf("Ceiling Color: %i %i %i\n"RESET"\n", game->walls.ceiling.r, game->walls.ceiling.g, game->walls.ceiling.b);
}

void	ft_print_all(t_game *game)
{
	int j, i = 0;
	while (i <= game->map.allocated_rows - 2)
	{
		j = 0;
		while (game->map.coords[i][j].type != '\n')
		{
			if (game->map.coords[i][j].x < 0)
				printf("(%i|", game->map.coords[i][j].x);
			else
				printf("(%i |", game->map.coords[i][j].x);
			if (game->map.coords[i][j].y < 0)
				printf("%i)", game->map.coords[i][j].y);
			else 
				printf(" %i)", game->map.coords[i][j].y);
			j++;
		}
		printf("\n");
		i++;
	}
}
void	ft_print_playable_field(t_game *game)
{
	int j, i = 0;
	while (i <= game->map.allocated_rows - 2)
	{
		j = 0;
		while (game->map.coords[i][j].type != '\n')
		{
			if (game->map.coords[i][j].x < 0 || game->map.coords[i][j].y < 0 \
				|| game->map.coords[i][j].y == game->map.allocated_rows - 3 \
					|| game->map.coords[i][j].x == game->map.map_length)
			{
				j++; 
				continue ;
			}
			printf("(%i |", game->map.coords[i][j].x);
			printf(" %i)", game->map.coords[i][j].y);
			j++;
		}
		printf("\n");
		i++;
	}
}

//just for testing purposes
void ft_print_map(t_game *game)
{
	int i = 0;
	int j = 0;
	while (i <= game->map.allocated_rows - 2)
	{
		j = 0;
		while (game->map.coords[i][j].type != '\n')
		{
			printf("%c", game->map.coords[i][j].type);
			j++;
		}
		printf("\n");
		i++;
	}
	ft_print_playable_field(game);
	i = 0;
	printf("\n");
	printf("Point Zero: C(%i | %i)\n\n", game->map.point_zero->x, game->map.point_zero->y);
	printf("Top Left: (%i | %i)\n", game->map.top_l->x, game->map.top_l->y);
	printf("Top Right: (%i | %i)\n", game->map.top_r->x, game->map.top_r->y);
	printf("Bottom Left: (%i | %i)\n", game->map.bottom_l->x, game->map.bottom_l->y);
	printf("Bottom Right: (%i | %i)\n", game->map.bottom_r->x, game->map.bottom_r->y);
	ft_print_params(game);
}