/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ****.h		                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ****** <******@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 12:33:17 by ******           #+#    #+#              */
/*   Updated: 2024/10/11 13:09:41 by ******           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H
# include "structs.h"

void	mini_map(t_game *game);
void put_pixel(int x, int y, int color, t_game *game);

//player.c
void init_player(t_player *player, t_map *map);
int key_release(int keycode, t_player *player);
int key_press(int keycode, t_game *game);
void move_player(t_player *player, t_map *map);

//ft_convert_map.c
void	ft_convert_map(t_game *game, t_map *map, int i);

//player.c
void init_player(t_player *player, t_map *map);
int ft_key_release(int keycode, t_player *player);
int ft_key_press(int keycode, t_game *game);
void move_player(t_player *player, t_map *map);

//ft_convert_map.c
void	ft_convert_map(t_game *game, t_map *map, int i);

//freeing_stuff.c
int				ft_free_map(t_game *game, int mode);
int				ft_free_game(t_game *game);
//map_parsing.c
int				ft_map_parsing(char *file_name, t_game *game);

//ft_save_args.c
bool			ft_save_args(t_game *game);

//ft_save_args_utils.c
bool			ft_check_args(t_game *game);

//map_parsing_utils.c
int				ft_read_map(int fd, t_game *game, int bytes);
int				ft_is_whitespace(char c);

//init.c
void			init(t_game *game);
//init.c
void			init(t_game *game);

//ft_save_map_utils.c
void			ft_set_map_side_barrier(t_game *game, int *x, int *y);
void			ft_set_map_barrier(t_game *game, char *map, int y);
void			ft_find_longest_row(t_game *game, char *map);
int				ft_is_map_char(char c);
void			ft_set_map_coords(t_game *game, int *i, int *x, int *y);
//ft_save_map.c
int				ft_save_map(t_game *game);

//ft_allocate_coords.c
t_coordinates	**ft_allocate_coords(t_game *game, int i);
int				ft_allocate_map_rows(t_game *game);

//map_check.c
void			ft_map_check(t_game *game);

//errors.c
void			print_error(char *str, t_game *game, int mode);

//game_utils.c
int				print_message(int mode, char *str);


void	ft_err_exit(char *str);

void	ft_err_map(char *str, t_game *game);

void	ft_err_game(char *str, t_game *game);

#endif