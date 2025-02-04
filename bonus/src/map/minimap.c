/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehedeman <ehedeman@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 12:15:57 by ehedeman          #+#    #+#             */
/*   Updated: 2025/01/03 14:53:54 by ehedeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static void	draw_mini(t_game *game, t_coordinates *start, int color)
{
	int				i;
	int				j;
	t_coordinates	save;

	save = *start;
	j = 0;
	i = 0;
	while (i < 7)
	{
		j = 0;
		start->y = save.y;
		while (j < 5)
		{
			put_pixel(start->x, start->y, color, game);
			start->y++;
			j++;
		}
		start->x++;
		i++;
	}
	start->x = save.x;
}

static void	draw_mini_map_loop(t_game *game, int *y, int x, \
	t_coordinates *start)
{
	int	color;

	while (*y < game->map.length - 1 && (*y < (int)(game->player.y / BLOCK) \
		+ 5 && start->y < HEIGHT - 10))
	{
		if (x < game->map.width && (game->map.map[*y][x] == '1' \
			|| game->map.map[*y][x] == '-'))
			color = 0x2E4D62;
		else if (*y == (int)(game->player.y / BLOCK) && x == \
			(int)(game->player.x / BLOCK))
			color = 0xFFDA0B;
		else if (x < game->map.width && game->map.map[*y][x] == 'F')
			color = 0xFF000;
		else
			color = 0x8DA8AF;
		draw_mini(game, start, color);
		*y += 1;
	}
}

static void	draw_mini_map(t_game *game, t_coordinates *start, int x)
{
	int	y;

	start->x = (int)(WIDTH * 0.9);
	while (x < (int)(game->player.x / BLOCK + 5) && start->x < WIDTH - 10)
	{
		y = (int)(game->player.y / BLOCK) - 5;
		if (y < 0)
			y = 0;
		start->y = (int)(HEIGHT * 0.9);
		draw_mini_map_loop(game, &y, x, start);
		start->x += 5;
		x++;
	}
}

void	mini_map(t_game *game)
{
	t_coordinates	m_start;
	int				x;

	x = (int)(game->player.x / BLOCK - 5);
	if (x < 0)
		x = 0;
	draw_mini_map(game, &m_start, x);
}

// bool touch_mini(float px, float py, char **map)
// {
// 	int x = px / BLOCK;
// 	int y = py / BLOCK;
// 	if(map[y][x] == '1')
// 		return true;
// 	return false;
// }

// void	draw_mini_map(t_game *game)
// {
// 	for(int y = HEIGHT * 0.9; y < HEIGHT - 10; y++)
// 		for(int x = WIDTH * 0.9; x < WIDTH - 10; x++)
// 			put_pixel(x, y, 0, game);
// 	float fraction = PI / 3 / WIDTH; //needs to stay same
// 	float start_x = game->player.angle - PI / 6;
// 	int i = WIDTH * 0.9;
// 	while(i < WIDTH)
// 	{
// 		float cos_angle = cos(start_x);
// 		float sin_angle = sin(start_x);
// 		float ray_x = game->player.x;
// 		float ray_y = game->player.y;
// 		int color = 0xFFDA0B;
// 		while(!touch_mini(ray_x, ray_y, game->map.map))
// 		{
// 			put_pixel(ray_x, ray_y, color, game);	//for 2D view
// 			ray_x += cos_angle;
// 			ray_y += sin_angle;
// 		}
// 		start_x += fraction;
// 		i++;
// 	}
// }