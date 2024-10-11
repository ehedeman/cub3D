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

int	ft_skip_til_map(t_game *game)
{
	int	i;

	i = 0;
	while (game->map.content[i])
	{
		while (game->map.content[i] && is_whitespace(game->map.content[i]))	//skip whitespace
			i++;
		if (game->map.content[i] && game->map.content[i] != "1")			//if its not wall of map
		{
			while (game->map.content[i] && game->map.content[i] != "\n")	//skip until newline
				i++;
			if (game->map.content[i])										//skip newline
				i++;
		}
	}
}

int ft_is_map_char(char c)
{
    if (c == "1" || c == "0" || c == "N" || c == "S" || c == "E" || c == "W")
        return (0);
    return (1);
}

int	ft_read_map(int fd, t_game *game)
{
	char	*str;
	char	*temp;

	while (1)
	{
		str = get_next_line(fd);
		if (!str)
			break ;
		temp = game->map.content;
		game->map.content = ft_strjoin(game->map.content, str);
		if (!game->map.content)
			return (1);
		free(temp);
		free(str);
	}
	return (0);
}
//might be leaking idk if i missed a case