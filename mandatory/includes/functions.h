/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalchuk <svalchuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 13:32:37 by ehedeman          #+#    #+#             */
/*   Updated: 2024/11/03 13:12:16 by svalchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H
# include "structs.h"

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

//main_utils.c
void			ft_set_zero(t_game *game);

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

//key_handling.c
int				key_handler(int key, t_game *game);

//ft_init_game.c
int				ft_game(t_game *game);

//movement.c
int				ft_check_for_walls(int direction, t_coordinates **coords, \
			t_player *player);
void			ft_change_current_location(t_player *player, int direction, \
			t_coordinates **coords);
void			ft_change_current_orientation(int key, t_player *player);

//check_directions.c
int				ft_check_direction(int key, t_player *player);

//game_utils.c
int				print_message(int mode, char *str);

//DEBUG
void	ft_print_params(t_game *game);
void	ft_print_all(t_game *game);
void	ft_print_playable_field(t_game *game);
void ft_print_map(t_game *game);

#endif