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

#include "../includes/cub3D.h"

//might be leaking idk if i missed a case
int	ft_read_map(int fd, t_game *game, int bytes)
{
	char	*str;

	game->map.content = ft_calloc(1, 1);
	str = NULL;
	while (bytes)
	{
		str = malloc(sizeof(char) * (40 + 1));
		if (!str)
			return (1);
		bytes = read(fd, str, 40);
		if (bytes == -1)
		{
			free(str);
			return (1);
		}
		str[bytes] = '\0';
		game->map.content = ft_strjoin_get(game->map.content, str);
		if (!game->map.content)
			return (1);
	}
	return (0);
}

//newline not included because newlines are important for subject
int	ft_is_whitespace(char c)
{
	if (c == '\t' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}
