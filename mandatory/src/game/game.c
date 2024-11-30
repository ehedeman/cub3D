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

static int	close_window(t_game *game);

void	ft_init_game(t_game *game);
int draw_loop(t_game *game);
void ft_print_map(t_map *map);

void    ft_game(char *map_path)
{
    t_game  *game;

    game = ft_calloc(1, sizeof(t_game));
    if (!game)
        ft_err_exit("Failed to allocate memory for game\n");
    game->map.content = map_path;
    ft_init_game(game);
    ft_print_map(&game->map);
    mlx_hook(game->mlx.window, KeyPress, KeyPressMask, ft_key_press, game);
    mlx_hook(game->mlx.window, KeyRelease, KeyReleaseMask, ft_key_release, &game->player);
    mlx_loop_hook(game->mlx.init, draw_loop, game);
    mlx_hook(game->mlx.window, DestroyNotify, 0, ft_close_window, game);
    mini_map(game);
    mlx_loop(game->mlx.init);
}

static int	close_window(t_game *game)
{
	print_error("Window closed\nThanks for playing\n", game, 0);
	return (0);
}
