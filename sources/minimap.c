/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehedeman <ehedeman@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 12:15:57 by ehedeman          #+#    #+#             */
/*   Updated: 2024/11/18 14:10:31 by ehedeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"


static void		draw_mini(t_game *game, t_coordinates *start, t_coordinates *end,
							int colour)
{
	t_coordinates	save;

	save = *start;
	while (start->x < end->x)
	{
		start->y = save.y;
		while (start->y < end->y)
		{
			put_pixel(start->x, start->y, colour, game);
			start->y++;
		}
		start->x++;
	}
}

static void	draw_mini_map(t_game *game, t_coordinates *start, t_coordinates *end)
{
	int	x;
	int	y;
	int	color;

	x = 0;
	while (x < game->map.width - 1)
	{
		y = 0;
		while (y < game->map.length - 1)
		{
			start->x = (int)(end->x - game->map.width * 5) + (x * 5);
			start->y = (int)(end->y - game->map.length * 5) + (y * 5);
			if (game->map.coordinates[y][x] == '1' || game->map.coordinates[y][x] == '-')
				color = 0x2E4D62;
			else if (y == (int)(game->player.y / (HEIGHT / game->map.length) + 1) && x == (int)(game->player.x / (WIDTH / game->map.width)))
				color = 0xFFDA0B;
			else
				color = 0x8DA8AF;
			printf("%i|%i\n",(int)(game->player.x / (WIDTH / game->map.width)), (int)(game->player.y / (HEIGHT / game->map.length)));
			draw_mini(game, start, end, color);
			y++;
		}
		x++;
	}
}

// static void	draw_mini_map(t_game *game, t_coordinates *start, t_coordinates *end)
// {
// 	int	x;
// 	int	y;
// 	int	color;

// 	x = 0;
// 	while (x < game->map.width - 1)
// 	{
// 		y = 0;
// 		while (y < game->map.length - 1)
// 		{
// 			start->x = (int)(end->x - game->map.width * 5) + (x * 5);
// 			start->y = (int)(end->y - game->map.length * 5) + (y * 5);
// 			if (game->map.coordinates[y][x] == '1' || game->map.coordinates[y][x] == '-')
// 				color = 0x2E4D62;
// 			else if (y == (int)game->player.y / BLOCK && x == (int)game->player.x / BLOCK)
// 				color = 0xFFDA0B;
// 			else
// 				color = 0x8DA8AF;
// 			draw_mini(game, start, end, color);
// 			y++;
// 		}
// 		x++;
// 	}
// }

void	mini_map(t_game *game, int mode)
{
	t_coordinates m_start;
	t_coordinates m_end;
	
	m_end.x = (int)(WIDTH * 0.9);
	m_end.y = (int)(HEIGHT * 0.9);
	if (mode)
		draw_mini_map(game, &m_start, &m_end);
	else
		draw_mini_map(game, &m_start, &m_end);
}