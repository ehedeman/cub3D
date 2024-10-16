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
	i = 0;
	while (i <= game->map.allocated_rows - 2)
	{
		j = 0;
		while (game->map.coords[i][j].type != '\n')
		{
			printf("(%i | %i) ", game->map.coords[i][j].x, game->map.coords[i][j].y);
			j++;
		}
		printf("\n");
		i++;
	}
	printf("\n");
	printf("Point Zero: C(%i | %i)\n\n", game->map.point_zero->x, game->map.point_zero->y);
	printf("Top Left: (%i | %i)\n", game->map.top_l->x, game->map.top_l->y);
	printf("Top Right: (%i | %i)\n", game->map.top_r->x, game->map.top_r->y);
	printf("Bottom Left: (%i | %i)\n", game->map.bottom_l->x, game->map.bottom_l->y);
	printf("Bottom Right: (%i | %i)\n", game->map.bottom_r->x, game->map.bottom_r->y);
}

int main(int argc, char **argv)
{
	t_game	game;
	
	if (argc != 2)
	{
		printf("Wrong number of arguments!");
		exit(1);
	}
	ft_set_zero(&game);
	// if (!(ft_check_extension(argv[1])))
	// {
	// 	printf("Wrong file extension!");
	// 	exit(1);
	// }
	ft_map_parsing(argv[1], &game); //doesnt need if and exit because the error print fucntion exits
	// if (argc == 2 && ft_check_extension(argv[1]))
	// {
	ft_print_map(&game);	//just for testing purposes
	ft_init_game(&game);
	mlx_loop(game.mlx);
	ft_free_map(&game, 0);	//0 is the return value to save lines (you can put the function into return statement that way)
	return (0);
}
//put the game struct init after the map because the player
//and wall structs need the map coordinates