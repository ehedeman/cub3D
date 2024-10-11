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

int	ft_save_map(t_game *game)
{
	int	i;
	int	x;
	int	y;

	i = ft_skip_til_map(game);
	x = 0;
	y = 0;
	while (game->map.content[i])
	{
		while (game->map.content[i] && game->map.content[i] != "\n")	//save until \n, then y + 1
		{
			if (ft_is_map_char(game->map.content[i]))					//if not a map_char then save as -
				game->map.coords[y][x].type = "-";
			else
				game->map.coords[y][x].type = game->map.content[i];
			game->map.coords[y][x].x = x;
			game->map.coords[y][x].y = y;
			i++;
			x++;
		}
		x = 0;
		y++;
		if (game->map.content[i])
			i++;
	}
}

int	ft_map_parsing(char *file_name, t_game *game)
{
	int	fd;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		printf("Error\nFailed to open file\n");
	else if (fd)
		game->map.content = ft_read_map(fd, game);
	if (ft_check_map_format())
		printf("something\n");
	else if (ft_save_args())
		printf("something went wrong\n"); //change later
	else if (ft_save_map(game))
		printf("something went wrong\n");
	else
		return (0);
	return (1);
}