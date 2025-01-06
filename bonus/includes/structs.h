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

#ifndef STRUCTS_H
# define STRUCTS_H
# include "cub3D.h"

enum e_side
{
	_s_null,
	_s_north,
	_s_south,
	_s_west,
	_s_east,
	_s_exit
};

typedef struct s_coordinates
{
	float			x;
	float			y;
	int				type;
}			t_coordinates;

typedef struct s_raycast
{
	int				color;
	float			dist;
	float			height;
	int				start_y;
	int				end;
	int				from_mid;
	int				pos_y;
	int				i;
}			t_raycast;

typedef struct s_player
{
	t_coordinates	start;
	char			orientation;

	float			x;
	float			y;
	float			angle;
	float			cos_angle;
	float			sin_angle;
	bool			key_up;
	bool			key_down;
	bool			key_left;
	bool			key_right;
	bool			left_rotate;
	bool			right_rotate;
}				t_player;

typedef struct s_rgb
{
	int				r;
	int				g;
	int				b;
}				t_rgb;

typedef struct s_args
{
	char			*north;
	char			*south;
	char			*east;
	char			*west;
	char			*exit;
	t_rgb			floor;
	t_rgb			ceiling;
}				t_args;

// content = contents of the map file
// length = amount of rows in the coords array
// length = amount of rows in the coords array
// -> (incl negative space and NULL row at end)
// width = length of longest row
// width = length of longest row
// point_zero = bottom_l so it works like a normal coordinate system
// coords = array of coordinates

typedef struct s_map
{
	char			*content;
	t_coordinates	**coords;
	char			**map;
	int				length;
	int				width;
	t_coordinates	fin;
}			t_map;

typedef struct s_mlx
{
	void			*init;
	void			*window;
}				t_mlx;

typedef struct s_img
{
	void			*img;
	char			*addr;
	int				bpp;
	int				ll;
	int				endian;
	int				width;
	int				height;
	t_coordinates	t_step;
	t_coordinates	pos;
}			t_img;

typedef struct s_tex
{
	t_img			*north;
	t_img			*south;
	t_img			*east;
	t_img			*west;
	t_img			*exit;
}			t_tex;

typedef struct s_game
{
	t_mlx			mlx;
	t_args			args;
	t_map			map;
	t_tex			walls;
	t_player		player;
	t_raycast		ray;
	void			*img;
	char			*data;
	int				bpp;
	int				size_line;
	int				endian;
	int				side;
	int				exit_found;
}				t_game;

#endif