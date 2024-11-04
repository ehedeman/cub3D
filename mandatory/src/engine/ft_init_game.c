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

int	close_window(t_game *game)
{
	print_error("Window closed\n", game, 0);
	exit(0);
	return (0);
}

void	ft_set_current_orientation(t_player *player)
{
	if (player->start_orientation == 'N')
		player->current_orientation = NO;
	if (player->start_orientation == 'S')
		player->current_orientation = SO;
	if (player->start_orientation == 'E')
		player->current_orientation = EA;
	if (player->start_orientation == 'W')
		player->current_orientation = WE;
}

void	ft_set_player_location(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (i++ < game->map.allocated_rows - 1)
	{
		j = -1;
		while (j++ < game->map.map_length)
		{
			if (game->map.coords[i][j].type == 'N' \
				|| game->map.coords[i][j].type == 'S' \
					|| game->map.coords[i][j].type == 'W' \
						|| game->map.coords[i][j].type == 'E')
			{
				game->player.current = &game->map.coords[i][j];
				game->player.start_orientation = game->player.current->type;
				ft_set_current_orientation(&game->player);
				printf("Player Location: (%i|%i), %c, %i\n", \
					game->player.current->x, game->player.current->y, \
						game->player.start_orientation, \
							game->player.current_orientation);
				return ;
			}
		}
	}
}

char **get_map(void)
{
    char **map = malloc(sizeof(char *) * 11);
    map[0] = "111111111111111";
    map[1] = "100000000000001";
    map[2] = "100000000000001";
    map[3] = "100000100000001";
    map[4] = "100000000000001";
    map[5] = "100000010000001";
    map[6] = "100001000000001";
    map[7] = "100000000000001";
    map[8] = "100000000000001";
    map[9] = "111111111111111";
    map[10] = NULL;
    return (map);
}

void init_player(t_player *player)
{
    player->x = SCREEN_W / 2;
    player->y = SCREEN_H / 2;
    player->angle = PI / 2;

    player->key_up = false;
    player->key_down = false;
    player->key_right = false;
    player->key_left = false;

    player->left_rotate = false;
    player->right_rotate = false;
}

void ft_init_game(t_game *game)
{
	init_player(&game->player);
	game->test_map = get_map();
	game->mlx.mlx = mlx_init();
	game->mlx.mlx_window = mlx_new_window(game->mlx.mlx, SCREEN_W, SCREEN_H, "cub3D");
	game->mlx.img = mlx_new_image(game->mlx.mlx, SCREEN_W, SCREEN_H);
	game->mlx.data = mlx_get_data_addr(game->mlx.img, &game->mlx.bpp, &game->mlx.ll, &game->mlx.endian);
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.mlx_window, game->mlx.img, 0, 0);
}

int key_press(int keycode, t_player *player)
{
    if(keycode == KEY_W)
        player->key_up = true;
    if(keycode == KEY_S)
        player->key_down = true;
    if(keycode == KEY_A)
        player->key_left = true;
    if(keycode == KEY_D)
        player->key_right = true;
    if(keycode == KEY_LEFT)
        player->left_rotate = true;
    if(keycode == KEY_RIGHT)
        player->right_rotate = true;
    return 0;
}

int key_release(int keycode, t_player *player)
{
    if(keycode == KEY_W)
        player->key_up = false;
    if(keycode == KEY_S)
        player->key_down = false;
    if(keycode == KEY_A)
        player->key_left = false;
    if(keycode == KEY_D)
        player->key_right = false;
    if(keycode == KEY_LEFT)
        player->left_rotate = false;
    if(keycode == KEY_RIGHT)
        player->right_rotate = false;
    return 0;
}

void move_player(t_player *player)
{
    int speed = 3;
    float angle_speed = 0.03;
    float cos_angle = cos(player->angle);
    float sin_angle = sin(player->angle);

    if (player->left_rotate)
        player->angle -= angle_speed;
    if (player->right_rotate)
        player->angle += angle_speed;
    if (player->angle > 2 * PI)
        player->angle = 0;
    if (player->angle < 0)
        player->angle = 2 * PI;

    if (player->key_up)
    {
        player->x += cos_angle * speed;
        player->y += sin_angle * speed;
    }
    if (player->key_down)
    {
        player->x -= cos_angle * speed;
        player->y -= sin_angle * speed;
    }
    if (player->key_left)
    {
        player->x += sin_angle * speed;
        player->y -= cos_angle * speed;
    }
    if (player->key_right)
    {
        player->x -= sin_angle * speed;
        player->y += cos_angle * speed;
    }
}

void put_pixel(int x, int y, int color, t_game *game)
{
    if(x >= SCREEN_W || y >= SCREEN_H || x < 0 || y < 0)
        return;
    
    int index = y * game->mlx.ll + x * game->mlx.bpp / 8;
    game->mlx.data[index] = color & 0xFF;
    game->mlx.data[index + 1] = (color >> 8) & 0xFF;
    game->mlx.data[index + 2] = (color >> 16) & 0xFF;
}

// our own clear_image
void clear_image(t_game *game)
{
    for(int y = 0; y < SCREEN_H; y++)
        for(int x = 0; x < SCREEN_W; x++)
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
    char **map = game->test_map;
    int color = 0x0000FF;
    for(int y = 0; map[y]; y++)
        for(int x = 0; map[y][x]; x++)
            if(map[y][x] == '1')
                draw_square(x * TEXTURE_RES, y * TEXTURE_RES, TEXTURE_RES, color, game);
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
bool touch(float px, float py, t_game *game)
{
    int x = px / TEXTURE_RES;
    int y = py / TEXTURE_RES;
    if(game->test_map[y][x] == '1')
        return true;
    return false;
}

void draw_line(t_player *player, t_game *game, float start_x, int i)
{
    float cos_angle = cos(start_x);
    float sin_angle = sin(start_x);
    float ray_x = player->x;
    float ray_y = player->y;

    while(!touch(ray_x, ray_y, game))
    {
        if(DEBUG)
            put_pixel(ray_x, ray_y, 0xFF0000, game);
        ray_x += cos_angle;
        ray_y += sin_angle;
    }
    if(!DEBUG)
    {
        float dist = fixed_dist(player->x, player->y, ray_x, ray_y, game);
        float height = (TEXTURE_RES / dist) * (SCREEN_W / 2);
        int start_y = (SCREEN_H - height) / 2;
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
    move_player(player);
    clear_image(game);
    if(DEBUG)
    {
        draw_square(player->x, player->y, 10, 0x00FF00, game);
        draw_map(game);
    }
    float fraction = PI / 3 / SCREEN_W;
    float start_x = player->angle - PI / 6;
    int i = 0;
    while(i < SCREEN_W)
    {
        draw_line(player, game, start_x, i);
        start_x += fraction;
        i++;
    }
    mlx_put_image_to_window(game->mlx.mlx, game->mlx.mlx_window, game->mlx.img, 0, 0);
    return 0;
}



int	ft_game(t_game *game)
{
	// ft_set_player_location(game);
	ft_init_game(game);	 
	mlx_hook(game->mlx.mlx_window, EVENT_DESTROY, 1L<<0, close_window, game);
	mlx_hook(game->mlx.mlx_window, EVENT_KEY_PRESS, 1L<<0, key_press, &game->player);
	mlx_hook(game->mlx.mlx_window, EVENT_KEY_RELEASE, 1L<<1, key_release, &game->player);
	mlx_loop_hook(game->mlx.mlx, draw_loop, game);
	mlx_loop(game->mlx.mlx);
	return (0);
}

/* int	ft_init_game(t_game *game)
{
	ft_set_player_location(game);
	game->mlx.mlx = mlx_init();
	if (!game->mlx.mlx)
		print_error("Error\nGame allocation failed.\n", game, 1);
	game->mlx.mlx_window = mlx_new_window(game->mlx.mlx, game->mlx.win_width, \
		game->mlx.win_height, "cub3D");
	if (!game->mlx.mlx_window)
		print_error("Error\nGame allocation failed.\n", game, 1);
	if (mlx_hook(game->mlx.mlx_window, 17, 1L << 0, close_window, game) == 0)
		print_error("Error\nGame allocation failed\n", game, 1);
	if (mlx_key_hook(game->mlx.mlx_window, key_handler, game) == 0)
		print_error("Error\nGame allocation failed\n", game, 1);
	if (mlx_hook(game->mlx.mlx_window, 2, 1L << 0, key_handler, game) == 0)
		print_error("Error\nGame allocation failed\n", game, 1);
	if (mlx_hook(game->mlx.mlx_window, 17, 1L << 0, close_window, game) == 0)
		print_error("Error\nGame allocation failed\n", game, 1);
	int height = WALL_HEIGHT;
	int width = WALL_WIDTH;
	game->mlx.test = mlx_xpm_file_to_image(game->mlx.mlx, WALL_XPM,
			&width, &height);
	if (!game->mlx.test)
		print_error("Error\nImage allocation failed.\n", game, 1);
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.mlx_window, \
			game->mlx.test, 200, 200); 
	return (0);
} */

	// for testing of images and shit
	// int	height;
	// int	width;

	// height = WALL_HEIGHT;
	// width = WALL_WIDTH;
	// game->mlx.test = mlx_xpm_file_to_image(game->mlx.mlx, WALL_XPM,
	// 		&width, &height);
	// if (!game->mlx.test)
	// 	print_error("Error\nImage allocation failed.\n", game, 1);
	// mlx_put_image_to_window(game->mlx.mlx, game->mlx.mlx_window, \
	// 		game->mlx.test, 1200, 800);