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

bool	ft_check_args(t_game *game)
{
	if (!game->args.north || !game->args.south || !game->args.east
		|| !game->args.west)
		return (true);
	return (false);
}

static size_t	get_param_len(const char *s, size_t n);

char	*get_param(const char *s, size_t n)
{
	char	*dup;
	size_t	i;
	size_t	j;
	size_t	len;

	len = get_param_len(s, n);
	dup = (char *)malloc(len + 1);
	if (!dup)
		return (NULL);
	i = 0;
	j = 0;
	while (i < n && s[i] != '\n')
	{
		if (s[i] != ' ')
		{
			dup[j] = s[i];
			j++;
		}
		i++;
	}
	dup[j] = '\0';
	return (dup);
}

static size_t	get_param_len(const char *s, size_t n)
{
	size_t	len;
	size_t	i;

	len = 0;
	i = 0;
	while (i < n && s[i] != '\n')
	{
		if (s[i] != ' ')
			len++;
		i++;
	}
	return (len);
}

bool	ft_parse_rgb(const char *str, int *r, int *g, int *b)
{
	while (*str == ' ')
		str++;
	while (*str && *str != ',' && *str != ' ')
		*r = *r * 10 + (*str++ - '0');
	while (*str == ',' || *str == ' ')
		str++;
	if (!*str)
		return (false);
	while (*str && *str != ',' && *str != ' ')
		*g = *g * 10 + (*str++ - '0');
	while (*str == ',' || *str == ' ')
		str++;
	if (!*str)
		return (false);
	while (*str && *str != '\0' && *str != '\n' && *str != ' ')
		*b = *b * 10 + (*str++ - '0');
	if (*r < 0 || *r > 255 || *g < 0 || *g > 255 || *b < 0 || *b > 255)
		return (false);
	return (true);
}

void	ft_assign_tex_ea_we(t_game *game, const char *param, const char *i)
{
	if (ft_strncmp(i, "WE ", 3) == 0)
	{
		if (!game->args.west)
			game->args.west = ft_strndup(param, strlen(param));
		else
			print_error("Error\nDouble Map Arguments.\n", game, 1);
	}
	else if (ft_strncmp(i, "EA ", 3) == 0)
	{
		if (!game->args.east)
			game->args.east = ft_strndup(param, strlen(param));
		else
			print_error("Error\nDouble Map Arguments.\n", game, 1);
	}
}
