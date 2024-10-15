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

int	ft_map_parsing(char *file_name, t_game *game)
{
	int	fd;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		printf("Error\nFailed to open file\n");
	else if (fd)
	{
		if (ft_read_map(fd, game))
		{
			printf("something went wrong.\n");
			return (1);
		}
	}
	// if (ft_check_map_format())
	// 	printf("something\n");
	// else if (ft_save_args())
	// 	printf("something went wrong\n"); //change later
	if (ft_save_map(game, 0, 0))
	{
		printf("something went wrong\n");
		return (1);
	}
	return (0);
}