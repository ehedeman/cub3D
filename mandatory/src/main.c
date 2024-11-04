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

int	main(int argc, char **argv)
{
	t_game	game;
	
	// ft_set_zero(&game);
	if (argc != 2)
		print_error("Error\nWrong number of arguments!\n", &game, 1);
	if (!(ft_check_extension(argv[1])))
	{
		printf("Wrong file extension!\n");
		exit(1);
	}
	ft_map_parsing(argv[1], &game);
	ft_print_map(&game);
	ft_game(&game);
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
