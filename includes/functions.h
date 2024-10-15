/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehedeman <ehedeman@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 13:32:37 by ehedeman          #+#    #+#             */
/*   Updated: 2024/10/15 12:38:52 by ehedeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "structs.h"
//for map parsing

//map_parsing.c
int				ft_map_parsing(char *file_name, t_game *game);

//map_parsing_utils.c
int				ft_read_map(int fd, t_game *game);
int				ft_free_map(t_game *game, int mode);
int				ft_is_whitespace(char c);
void			ft_set_zero(t_game *game);

//ft_save_map_utils.c
void			ft_set_map_side_barrier(t_game *game, int *x, int *y);
void	        ft_set_map_barrier(t_game *game, char *map, int y);
void			ft_find_longest_row(t_game *game, char *map);
//ft_save_map.c
int				ft_save_map(t_game *game, int x, int y);

//ft_allocate_coords.c
t_coordinates	**ft_allocate_coords(t_game *game, int i);
//int				ft_allocate_map_rows(t_game *game, int i);
int	ft_allocate_map_rows(t_game *game);