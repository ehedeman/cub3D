/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehedeman <ehedeman@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:08:05 by ehedeman          #+#    #+#             */
/*   Updated: 2024/11/06 14:31:08 by ehedeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

// our own put_pixel

void put_pixel(int x, int y, int color, t_game *game)
{
	if(x >= WIDTH || y >= HEIGHT || x < 0 || y < 0)
		return;
	
	int index = y * game->size_line + x * game->bpp / 8;
	game->data[index] = color & 0xFF;
	game->data[index + 1] = (color >> 8) & 0xFF;
	game->data[index + 2] = (color >> 16) & 0xFF;
}

// our own clear_image
void clear_image(t_game *game)
{
	for(int y = 0; y < HEIGHT; y++)
		for(int x = 0; x < WIDTH; x++)
			put_pixel(x, y, 0, game);
}

// utils functions
void draw_square(int x, int y, int size, int color, t_game *game)
{
	for(int i = 0; i < size; i++)
		put_pixel(x + i, y, color, game);
	for(int i = 0; i < size; i++)
		put_pixel(x, y + i, color, game);
	for(int i = 0; i < size; i++)
		put_pixel(x + size, y + i, color, game);
	for(int i = 0; i < size; i++)
		put_pixel(x + i, y + size, color, game);
}

void draw_map(t_game *game)
{
	char **map = game->map.coordinates;
	int color = 0x0000FF;
	for(int y = 0; map[y]; y++)
		for(int x = 0; x < game->map.width; x++)
			if(map[y][x] == '1')
				draw_square(x * BLOCK, y * BLOCK, BLOCK, color, game);
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

void init_game(t_game *game)
{
	ft_map_parsing(game->map.content, game);
	ft_convert_map(game, &game->map, 0);
	init_player(&game->player, &game->map);
//	game->map_array = get_map();
	game->mlx.mlx = mlx_init();
	game->win = mlx_new_window(game->mlx.mlx, WIDTH, HEIGHT, "Game");
	game->img = mlx_new_image(game->mlx.mlx, WIDTH, HEIGHT);
	game->data = mlx_get_data_addr(game->img, &game->bpp, &game->size_line, &game->endian);
	mlx_put_image_to_window(game->mlx.mlx, game->win, game->img, 0, 0);
}

// raycasting functions
void draw_line(t_player *player, t_game *game, float start_x, int i)
{
	float cos_angle = cos(start_x);
	float sin_angle = sin(start_x);
	float ray_x = player->x;
	float ray_y = player->y;

	while(!touch(ray_x, ray_y, game->map.coordinates))
	{
		if(DEBUG)
			put_pixel(ray_x, ray_y, 0xFF0000, game);
		ray_x += cos_angle;
		ray_y += sin_angle;
	}
	if(!DEBUG)
	{
		float dist = fixed_dist(player->x, player->y, ray_x, ray_y, game);
		float height = (BLOCK / dist) * (WIDTH / 2);
		int start_y = (HEIGHT - height) / 2;
		int end = start_y + height;
		while(start_y < end)
		{
			put_pixel(i, start_y, 255, game);
			start_y++;
		}
	}
}

int draw_loop(t_game *game)
{
	t_player *player = &game->player;
	move_player(player, &game->map);
	clear_image(game);
	if(DEBUG)
	{
		draw_square(player->x, player->y, 10, 0x00FF00, game);
		draw_map(game);
	}
	float fraction = PI / 3 / WIDTH;
	float start_x = player->angle - PI / 6;
	int i = 0;
	while(i < WIDTH)
	{
		draw_line(player, game, start_x, i);
		start_x += fraction;
		i++;
	}
	mlx_put_image_to_window(game->mlx.mlx, game->win, game->img, 0, 0);
	return 0;
}


static int	ft_check_extension(const char *argv)
{
	char	*ext;

	ext = ft_strrchr(argv, '.');
	if (ext)
		return (ft_strcmp(ext, ".cub") == 0);
	return (0);
}

void ft_print_map(t_map *map)
{
	int	i = 0;
	int	j = 0;

	while (map->coordinates[i])
	{
		j = 0;
		while (map->coordinates[i][j])
		{
			printf("%c", map->coordinates[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	printf("%p\n", map->coordinates[i]);
}

int main(int argc, char **argv)
{
	t_game game;
	// init
	init(&game);
	if (argc != 2)
		print_error("Error\nWrong number of arguments!\n", &game, 1);
	if (!(ft_check_extension(argv[1])))
	{
		printf("Wrong file extension!\n");
		exit(1);
	}
	game.map.content = argv[1];
	// ft_init_game(&game);
//------------------------------------------------------//
	init_game(&game);
	ft_print_map(&game.map);
	// hooks
	mlx_hook(game.win, 2, 1L<<0, key_press, &game);
	mlx_hook(game.win, 3, 1L<<1, key_release, &game.player);
	// draw loop
	mlx_loop_hook(game.mlx.mlx, draw_loop, &game);

	mlx_loop(game.mlx.mlx);
	ft_free_map(&game, 0);
	ft_free_game(&game);
	return 0;
}