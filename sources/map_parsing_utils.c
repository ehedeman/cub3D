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

int	ft_read_map(int fd, t_game *game)
{
	char	*str;
	int		bytes;
	char	*temp;

	str = malloc(sizeof(char) * (40 + 1));
	if (!str)
		return (1);
	bytes = 1;
	while (bytes)
	{
		bytes = read(fd, str, 40);
		if (bytes == -1)
		{
			free(str);
			return (1);
		}
		str[bytes] = '\0';
		temp = game->map.content;
		game->map.content = ft_strjoin(game->map.content, str);
		if (!game->map.content)
			return (1);
		if (temp)
			free(temp);
	}
	free(str);
	return (0);
}
//might be leaking idk if i missed a case

int	ft_free_map(t_game *game, int mode)
{
	int	i;

	i = 0;
	while (i <= game->map.allocated_rows - 1)
	{
		if (game->map.coords[i])		//should work because its set to NULL unless allocated
			free(game->map.coords[i]);
		i++;
	}
	free(game->map.coords);
	return (mode);							//1 for the error_return, 0 for normal free so function can be used elsewhere
}

int	ft_is_whitespace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}

void	ft_set_zero(t_game *game)
{
	game->map.content = NULL;
	game->map.coords = NULL;
}