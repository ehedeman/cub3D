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

/*-------------------------------game folder----------------------------------*/

//game.c
void			ft_game(char *map_path);
//init_game.c
void			ft_init_game(t_game *game);

/*------------------------------render folder---------------------------------*/

//color.c
int				get_pixel_color(float *ray_x, float *ray_y, int z, \
	t_game *game);
//render.c
int				draw_loop(t_game *game);
void			ft_print_map(t_map *map);
//render_utils.c
void			put_pixel(int x, int y, int color, t_game *game);
bool			touch(float px, float py, t_map *map);
void			clear_image(t_game *game);
float			distance(float x, float y);
float			fixed_dist(float x2, float y2, t_game *game);
//crash_avoiding.c
bool			avoid_crash(t_game *game, float *ray_x, float *ray_y);

/*-------------------------------player folder--------------------------------*/

//player_utils.c
int				is_wall(t_player *player, t_map *map);
//player.c
void			init_player(t_player *player, t_map *map);
int				ft_key_release(int keycode, t_player *player);
int				ft_key_press(int keycode, t_game *game);
void			move_player(t_player *player, t_map *map);

/*-------------------------------map folder-----------------------------------*/

//ft_convert_map.c
void			ft_convert_map(t_game *game, t_map *map, int i);
//map_parsing.c
int				ft_map_parsing(char *file_name, t_game *game);
//ft_save_args.c
bool			ft_save_args(t_game *game, int i);
//ft_save_args_utils.c
bool			ft_check_args(t_game *game);
char			*get_param(const char *s, size_t n);
bool			ft_parse_rgb(const char *str, int *r, int *g, int *b);
//map_parsing_utils.c
int				ft_read_map(int fd, t_game *game, int bytes);
int				ft_is_whitespace(char c);
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

/*-------------------------------utils folder---------------------------------*/
//print.c
int				print_message(int mode, char *str);

//free.c
int				ft_free_map(t_game *game, int mode);
int				ft_free_game(t_game *game);

//free_utils.c
int				ft_free_coords(t_game *game, int mode);

//errors.c
void			print_error(char *str, t_game *game, int mode);
void			ft_err_exit(char *str);
void			ft_err_map(char *str, t_game *game);
void			ft_err_game(char *str, t_game *game);

#endif