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

static int	ft_check_extension(const char *argv);
void    ft_game(char *map_path);

int main(int argc, char **argv)
{
    if (argc != 2)
        ft_err_exit("Wrong number of arguments!\n");
    if (!ft_check_extension(argv[1]))
        ft_err_exit("Wrong file extension!\n");
    ft_game(argv[1]);
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
