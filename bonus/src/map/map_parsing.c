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

int	ft_map_parsing(char *file_name, t_game *game)
{
	int	fd;

	if (ft_strnstr(file_name, "maps/", 5))
		fd = open(file_name, O_RDONLY);
	else
	{
		file_name = ft_strjoin("maps/", file_name);
		fd = open(file_name, O_RDONLY);
		free(file_name);
	}
	if (fd == -1)
		print_error("Error\nFailed to open file\n", game, 1);
	else if (fd)
	{
		if (ft_read_map(fd, game, 1))
			print_error("Error\nFailed to read file.\n", game, 1);
	}
	if (!ft_save_args(game, 0))
		print_error("Error\nInvalid map args.\n", game, 1);
	ft_save_map(game);
	ft_map_check(game);
	return (0);
}
