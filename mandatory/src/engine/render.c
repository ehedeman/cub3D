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

void put_pixel(int x, int y, int color, t_game *game)
{
	if(x >= WIDTH || y >= HEIGHT || x < 0 || y < 0)
		return;
	
	int index = y * game->size_line + x * game->bpp / 8;
	game->data[index] = color & 0xFF;
	game->data[index + 1] = (color >> 8) & 0xFF;
	game->data[index + 2] = (color >> 16) & 0xFF;	//color developement (hat nix mit pixel zu tun)
}

// our own clear_image
void clear_image(t_game *game)
{
	for(int y = 0; y < HEIGHT; y++)
		for(int x = 0; x < WIDTH; x++)
			put_pixel(x, y, 0, game);
}

// distance calculation functions
float distance(float x, float y){
	return sqrt(x * x + y * y);
}

float fixed_dist(float x1, float y1, float x2, float y2, t_game *game)
{
	float delta_x = x2 - x1;
	float delta_y = y2 - y1;
	float angle = atan2(delta_y, delta_x) - game->player.angle;
	float fix_dist = distance(delta_x, delta_y) * cos(angle);
	return fix_dist;
}

// touch function 
bool touch(float px, float py, char **map)
{
	int x = px / BLOCK;
	int y = py / BLOCK;
	if(map[y][x] == '1')
		return true;
	return false;
}

int	get_pixel_color(float *ray_x, float *ray_y, int z, t_game *game)
{
	t_img *t;
	char *pixel;
	int	x;
	int	y;

	x = 0, y = 0;
	if (game->side == _s_north)
		t = game->tex.north;
	else if (game->side == _s_south)
		t = game->tex.south;
	else if (game->side == _s_west)
		t = game->tex.west;
	else if (game->side == _s_east)
		t = game->tex.east;
	else
		return (0);
	if (game->side == _s_north || game->side == _s_south)
		x = (int)*ray_x;
	if (game->side == _s_east || game->side == _s_west)
		x = (int)*ray_y;
	y = z + t->height / 2;
	// while (y < 0)
	// 	y += t->height / 2;
	y %= t->height;
	x %= t->width;
	if (x >= 0 && x < t->width && y >= 0 && y < t->height)
	{
		pixel = t->addr + (y * t->ll + (x * (t->bpp / 8)));
		return (*(int *)pixel);
	}
	return (0);
}

int calc_side(float x, float y, float cos_angle, float sin_angle, t_game *game)
{
	int dir = 0;
	int	sx;
	int	sy;

	sx = -1;
	sy = -1;

	// printf("%f\n", sin_angle);
	if (cos_angle > 0)
		sx = 1;
	if (sin_angle > 0)
		sy = 1;
	if (touch(x - sx, y, game->map.coordinates) || touch(x - sx, y - sy, game->map.coordinates))
	{
		dir = _s_north;
		if (sy == 1)
			dir = _s_south;
	}
	else if (touch(x, y - sy, game->map.coordinates) || touch(x, y, game->map.coordinates))
	{
		dir = _s_west;
		if (sx == 1)
			dir = _s_east;
	}
	// if (dir != 0)
	// 	printf("dir: %d\n", dir);
	return (dir);
}

// raycasting functions
void draw_line(t_player *player, t_game *game, float start_x, int i)
{
	float cos_angle = cos(start_x);
	float sin_angle = sin(start_x);
	float ray_x = player->x;
	float ray_y = player->y;
	int color = 0;
	(void)i;
	int j = 0;

	while(!touch(ray_x, ray_y, game->map.coordinates))
	{
		// put_pixel(ray_x, ray_y, 90, game);
		ray_x += cos_angle;
		ray_y += sin_angle;
	}

		// int num = calc_side(ray_x, ray_y, cos_angle, sin_angle, game);
		// if(num == _s_north)
		// 	put_pixel(ray_x, ray_y, 0xFF2A00, game); // red
		// if(num == _s_south)
		// 	put_pixel(ray_x, ray_y, 0x403DFF, game); // blue
		// if(num == _s_west)
		// 	put_pixel(ray_x, ray_y, 0xFFA600, game);
		// if(num == _s_east)
		// 	put_pixel(ray_x, ray_y, 0x00FF00, game); // green



	// printf("%f %f\n", ray_x, ray_y);
	game->side = calc_side(ray_x, ray_y, cos_angle, sin_angle, game);
	float dist = fixed_dist(player->x, player->y, ray_x, ray_y, game);
	// printf("%f\n", dist);
	float height = (BLOCK / dist) * (WIDTH / 2);
	int start_y = (HEIGHT - height) / 2;
	if(start_y < 0) start_y = 0;
	int end = start_y + height;
	if(end > 720)
		end = 720;

	while (j < HEIGHT)
	{
		if (j < start_y)
			color = game->tex.ceiling;	//ceiling
		else if (j > end)
			color = game->tex.floor;	//floor
		else
		{
			
			while(start_y < end)
			{
				int from_mid = -360 + start_y;
				// from_mid += 64;
				int pos_y = from_mid / (float) HEIGHT * dist;
				color = get_pixel_color(&ray_x, &ray_y, pos_y, game);
				put_pixel(i, start_y, color, game);
				start_y++;
			}
			j = start_y;
		}
		put_pixel(i, j, color, game);
		j++;
	}
}

int draw_loop(t_game *game)
{
	t_player *player = &game->player;
	move_player(player, &game->map);
	clear_image(game);
	float fraction = PI / 3 / WIDTH;
	float start_x = player->angle - PI / 6;
	int i = 0;
	while(i < WIDTH)
	{
		draw_line(player, game, start_x, i);
		start_x += fraction;
		i++;
	}
	mlx_put_image_to_window(game->mlx.init, game->mlx.window, game->img, 0, 0);
	mini_map(game);
	return 0;
}
