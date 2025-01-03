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

static void	ft_set_player_location(t_map *map, t_player *player)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->length)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->map[i][j] == 'N' \
				|| map->map[i][j] == 'S' \
					|| map->map[i][j] == 'W' \
						|| map->map[i][j] == 'E')
			{
				player->orientation = map->map[i][j];
				player->start.x = j;
				player->start.y = i;
				player->start.type = map->map[i][j];
				map->map[i][j] = '0';
				return ;
			}
			j++;
		}
		i++;
	}
}

void	init_player(t_player *player, t_map *map)
{
	ft_set_player_location(map, player);
	player->x = player->start.x * BLOCK;
	player->y = player->start.y * BLOCK;
	if (player->orientation == 'N')
		player->angle = 3 * PI / 2;
	else if (player->orientation == 'S')
		player->angle = PI / 2;
	else if (player->orientation == 'W')
		player->angle = PI;
	else if (player->orientation == 'E')
		player->angle = 0;
	player->key_up = false;
	player->key_down = false;
	player->key_right = false;
	player->key_left = false;
	player->left_rotate = false;
	player->right_rotate = false;
}

int	ft_key_press(int keycode, t_game *game)
{
	if (keycode == KEY_W)
		game->player.key_up = true;
	if (keycode == KEY_S)
		game->player.key_down = true;
	if (keycode == KEY_A)
		game->player.key_left = true;
	if (keycode == KEY_D)
		game->player.key_right = true;
	if (keycode == KEY_LEFT)
		game->player.left_rotate = true;
	if (keycode == KEY_RIGHT)
		game->player.right_rotate = true;
	if (keycode == KEY_ESC)
		print_error("ESC pressed\nThanks for playing\n", game, 0);
	return (0);
}

int	ft_key_release(int keycode, t_player *player)
{
	if (keycode == KEY_W)
		player->key_up = false;
	if (keycode == KEY_S)
		player->key_down = false;
	if (keycode == KEY_A)
		player->key_left = false;
	if (keycode == KEY_D)
		player->key_right = false;
	if (keycode == KEY_LEFT)
		player->left_rotate = false;
	if (keycode == KEY_RIGHT)
		player->right_rotate = false;
	return (0);
}
