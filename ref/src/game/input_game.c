/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperetia <mperetia@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 15:24:06 by mperetia          #+#    #+#             */
/*   Updated: 2024/07/27 13:55:18 by mperetia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static int	key_hook(int keycode, t_game *game);

int	key_action(int keycode, t_game *game)
{
	if (KEY_A == keycode || KEY_LEFT == keycode || KEY_D == keycode
		|| KEY_RIGHT == keycode || KEY_W == keycode || KEY_S == keycode
		|| KEY_ESC == keycode)
		key_hook(keycode, game);
	return (0);
}

static int	key_hook(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		exit_game(game);
	if (keycode == KEY_W)
		game->pressed.w = true;
	if (keycode == KEY_S)
		game->pressed.s = true;
	if (keycode == KEY_A)
		game->pressed.a = true;
	if (keycode == KEY_D)
		game->pressed.d = true;
	if (keycode == KEY_RIGHT)
		game->pressed.right = true;
	if (keycode == KEY_LEFT)
		game->pressed.left = true;
	return (0);
}

int	key_release_hook(int keycode, t_game *game)
{
	if (keycode == KEY_W && game->pressed.w)
		game->pressed.w = false;
	if (keycode == KEY_S && game->pressed.s)
		game->pressed.s = false;
	if (keycode == KEY_A && game->pressed.a)
		game->pressed.a = false;
	if (keycode == KEY_D && game->pressed.d)
		game->pressed.d = false;
	if (keycode == KEY_LEFT && game->pressed.left)
		game->pressed.left = false;
	if (keycode == KEY_RIGHT && game->pressed.right)
		game->pressed.right = false;
	return (0);
}

bool	moves_execute(t_game *game)
{
	if (game->pressed.w)
		move_front(game);
	if (game->pressed.s)
		move_back(game);
	if (game->pressed.a)
		move_left(game);
	if (game->pressed.d)
		move_right(game);
	if (game->pressed.left)
		rotate_left(game);
	if (game->pressed.right)
		rotate_right(game);
	return (true);
}
