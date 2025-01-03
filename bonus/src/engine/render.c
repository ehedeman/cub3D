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

static int	calc_side(float x, float y, t_game *game)
{
	int	dir;
	int	sx;
	int	sy;

	sx = -1;
	sy = -1;
	dir = 0;
	if (game->player.cos_angle > 0)
		sx = 1;
	if (game->player.sin_angle > 0)
		sy = 1;
	if (touch(x - sx, y, game->map.map) || touch(x - sx, y - sy, \
		game->map.map))
	{
		dir = _s_north;
		if (sy == 1)
			dir = _s_south;
	}
	else if (touch(x, y - sy, game->map.map) || touch(x, y, game->map.map))
	{
		dir = _s_west;
		if (sx == 1)
			dir = _s_east;
	}
	return (dir);
}

static void	draw_line_loop(t_game *game, int j, float ray_x, float ray_y)
{
	while (j < HEIGHT)
	{
		if (j < game->ray.start_y)
			game->ray.color = 0xFFF00;
		else if (j > game->ray.end)
			game->ray.color = 0xFFFF32;
		else
		{
			while (game->ray.start_y < game->ray.end)
			{
				game->ray.from_mid = -360 + game->ray.start_y;
				game->ray.pos_y = game->ray.from_mid / (float) HEIGHT * \
					game->ray.dist;
				game->ray.color = get_pixel_color(&ray_x, &ray_y, \
					game->ray.pos_y, game);
				put_pixel(game->ray.i, game->ray.start_y, \
					game->ray.color, game);
				game->ray.start_y++;
			}
			j = game->ray.start_y;
		}
		put_pixel(game->ray.i, j, game->ray.color, game);
		j++;
	}
}

static void	draw_line_calcs(int ray_x, int ray_y, t_game *game)
{
	int	j;

	j = 0;
	game->ray.color = 0;
	game->ray.dist = fixed_dist(ray_x, ray_y, game);
	game->ray.height = (BLOCK / game->ray.dist) * (WIDTH / 2);
	game->ray.start_y = (HEIGHT - game->ray.height) / 2;
	if (game->ray.start_y < 0)
		game->ray.start_y = 0;
	game->ray.end = game->ray. start_y + game->ray.height;
	if (game->ray.end > 720)
		game->ray.end = 720;
	draw_line_loop(game, j, ray_x, ray_y);
}

static void	draw_line(t_player *player, t_game *game, float start_x, int i)
{
	float	ray_x;
	float	ray_y;

	game->exit_found = 0;
	ray_y = player->y;
	ray_x = player->x;
	game->ray.i = i;
	player->cos_angle = cos(start_x);
	player->sin_angle = sin(start_x);
	while (!touch(ray_x, ray_y, game->map.map))
	{
		ray_x += player->cos_angle;
		ray_y += player->sin_angle;
	}
	if (t_exit(ray_x, ray_y, game->map.map))
		game->exit_found = 1;
	game->side = calc_side(ray_x, ray_y, game);
	draw_line_calcs(ray_x, ray_y, game);
}

int	draw_loop(t_game *game)
{
	t_player	*player;
	float		fraction;
	float		start_x;
	int			i;

	player = &game->player;
	move_player(player, &game->map);
	clear_image(game);
	fraction = PI / 3 / WIDTH;
	start_x = player->angle - PI / 6;
	i = 0;
	while (i < WIDTH)
	{
		draw_line(player, game, start_x, i);
		start_x += fraction;
		i++;
	}
	mini_map(game);
	mlx_put_image_to_window(game->mlx.init, game->mlx.window, \
		game->img, 0, 0);
	return (0);
}
