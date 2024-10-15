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
	if (ft_map_parsing(argv[1], &game))
		exit(1);	//print error message in funciton
	// if (argc == 2 && ft_check_extension(argv[1]))
	// {
	
	// }
	ft_print_map(&game);
	ft_free_map(&game, 0);
	free(game.map.content);
	return (0);
}
