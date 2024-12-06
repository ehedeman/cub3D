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

static void	ft_assign_param(t_game *game, int *i, int flag);
static void	ft_assign_texture(t_game *game, const char *param, const char *i);
static void	ft_assign_color(t_game *game, const char *param, const char *i);
static void	ft_parse_rgb(const char *str, int *r, int *g, int *b);

bool	ft_save_args(t_game *game)
{
	int	i;

	i = 0;
	while (game->map.content[i])
	{
		if (ft_is_whitespace(game->map.content[i]))
			i++;
		else if (ft_strncmp(&game->map.content[i], "NO ", 3) == 0)
			ft_assign_param(game, &i, 1);
		else if (ft_strncmp(&game->map.content[i], "SO ", 3) == 0)
			ft_assign_param(game, &i, 1);
		else if (ft_strncmp(&game->map.content[i], "WE ", 3) == 0)
			ft_assign_param(game, &i, 1);
		else if (ft_strncmp(&game->map.content[i], "EA ", 3) == 0)
			ft_assign_param(game, &i, 1);
		else if (ft_strncmp(&game->map.content[i], "F ", 2) == 0)
			ft_assign_param(game, &i, 2);
		else if (ft_strncmp(&game->map.content[i], "C ", 2) == 0)
			ft_assign_param(game, &i, 2);
		else
			i++;
	}
	if (ft_check_args(game))
		return (false);
	printf("\nNO: [%s]\n", game->args.north);
	printf("SO: [%s]\n", game->args.south);
	printf("WE: [%s]\n", game->args.west);
	printf("EA: [%s]\n", game->args.east);
	printf("F: [%d], [%d], [%d]\n", game->args.floor.r, game->args.floor.g, game->args.floor.b);
	printf("C: [%d], [%d], [%d]\n\n", game->args.ceiling.r, game->args.ceiling.g, game->args.ceiling.b);
	return (true);
}

static void	ft_assign_param(t_game *game, int *i, int flag)
{
	char	*value;
	int		start;
	int		end;

	start = *i;
	end = start;
	while (!ft_is_whitespace(game->map.content[end]))
		end++;
	end++;
	while (game->map.content[end] && game->map.content[end] != '\n')
		end++;
	if (flag == 1)
		value = get_param(&game->map.content[start + 3], end - start - 3);
	else
		value = get_param(&game->map.content[start + 2], end - start - 2);
	if (flag == 1)
		ft_assign_texture(game, value, &game->map.content[start]);
	else if (flag == 2)
		ft_assign_color(game, value, &game->map.content[start]);
	free(value);
	*i = end;
}

static void	ft_assign_texture(t_game *game, const char *param, const char *i)
{
	if (ft_strncmp(i, "NO ", 3) == 0)
		game->args.north = ft_strndup(param, strlen(param));
	else if (ft_strncmp(i, "SO ", 3) == 0)
		game->args.south = ft_strndup(param, strlen(param));
	else if (ft_strncmp(i, "WE ", 3) == 0)
		game->args.west = ft_strndup(param, strlen(param));
	else if (ft_strncmp(i, "EA ", 3) == 0)
		game->args.east = ft_strndup(param, strlen(param));
}

static void	ft_assign_color(t_game *game, const char *param, const char *i)
{
	int	r;
	int	g;
	int	b;

	r = 0;
	g = 0;
	b = 0;
	ft_parse_rgb(param, &r, &g, &b);
	if (ft_strncmp(i, "F ", 2) == 0)
	{
		game->args.floor.r = r;
		game->args.floor.g = g;
		game->args.floor.b = b;
	}
	else if (ft_strncmp(i, "C ", 2) == 0)
	{
		game->args.ceiling.r = r;
		game->args.ceiling.g = g;
		game->args.ceiling.b = b;
	}
}

static void	ft_parse_rgb(const char *str, int *r, int *g, int *b)
{
	while (*str == ' ')
		str++;
	while (*str && *str != ',' && *str != ' ')
		*r = *r * 10 + (*str++ - '0');
	while (*str == ',' || *str == ' ')
		str++;
	while (*str && *str != ',' && *str != ' ')
		*g = *g * 10 + (*str++ - '0');
	while (*str == ',' || *str == ' ')
		str++;
	while (*str && *str != '\0' && *str != '\n' && *str != ' ')
		*b = *b * 10 + (*str++ - '0');
}
