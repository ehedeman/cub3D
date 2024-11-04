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

static int	ft_check_extension(const char *argv);

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
	while (i <= game->map.length - 2)
	{
		j = 0;
		while (game->map.coords[i][j].type != '\n')
		{
			if (game->map.coords[i][j].x < 0)
				printf("(%f|", game->map.coords[i][j].x);
			else
				printf("(%f |", game->map.coords[i][j].x);
			if (game->map.coords[i][j].y < 0)
				printf("%f)", game->map.coords[i][j].y);
			else 
				printf(" %f)", game->map.coords[i][j].y);
			j++;
		}
		printf("\n");
		i++;
	}
}
void	ft_print_playable_field(t_game *game)
{
	int j, i = 0;
	while (i <= game->map.length - 2)
	{
		j = 0;
		while (game->map.coords[i][j].type != '\n')
		{
			if (game->map.coords[i][j].x < 0 || game->map.coords[i][j].y < 0 \
				|| game->map.coords[i][j].y == game->map.length - 3 \
					|| game->map.coords[i][j].x == game->map.width)
			{
				j++; 
				continue ;
			}
			printf("(%f |", game->map.coords[i][j].x);
			printf(" %f)", game->map.coords[i][j].y);
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
	while (i <= game->map.length)
	{
		j = 0;
		while (j < game->map.width)
		{
			printf("%c", game->map.coordinates[i][j].type);
			j++;
		}
		// if (game->map.coordinates[i][j].type == '\n')
		// 	printf("\n");
		i++;
	}
	printf("\n");
	ft_print_params(game);
}

// dont know if freeing the map at the end is nessecary, maybe if the game doesnt end via
// ESC or the x on the window but else idk because it exits because it gets there (i think)
int	main(int argc, char **argv)
{
	t_game	game;
	
	init(&game);
	if (argc != 2)
		print_error("Error\nWrong number of arguments!\n", &game, 1);
	if (!(ft_check_extension(argv[1])))
	{
		printf("Wrong file extension!\n");
		exit(1);
	}
	ft_map_parsing(argv[1], &game);
	ft_convert_map(&game, &game.map, -1, -1);
	ft_print_map(&game);
	ft_init_game(&game);
	mlx_loop(game.mlx.mlx);
	ft_free_map(&game, 0);
	return (0);
}

static int	ft_check_extension(const char *argv)
{
	char	*ext;

	ext = ft_strrchr(argv, '.');
	if (ext)
		return (ft_strcmp(ext, ".cub") == 0);
	return (0);
}
