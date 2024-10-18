/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehedeman <ehedeman@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 13:32:40 by ehedeman          #+#    #+#             */
/*   Updated: 2024/10/18 12:06:29 by ehedeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef enum e_direction
{
	LEFT = 0,
	RIGHT = 1,
	FOREWARD = 2,
	BACKWARD = 3,
}			t_direction;

typedef enum e_orientation
{
	NO = 0,
	EA = 1,
	SO = 2,
	WE = 3,
}			t_orientation;

/*

01234567
1
2
3
-> in array

3
2
1
01234567
-> in a coordinate system

which is why i have two seperate variables cuz i was tired of calculating shit
*/

// x/y -> just for printing
// x_array/y_array for changing locations etc
// t_coordinates dont need to be freed anywhere but in map.coords
typedef struct s_coordinates
{
	int	x;
	int	x_array;
	int	y;
	int	y_array;
	int	type;
}			t_coordinates;

// start->orientation = N, S, W, E, might not need it
typedef struct s_player
{
	t_coordinates	*current;
	t_coordinates	*next;
	char			start_orientation;
	int				current_orientation;
	void			*mlx;
}				t_player;

typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
}				t_rgb;

// north = path to north wall texture etc
typedef struct s_wall
{
	char	*north;
	char	*south;
	char	*east;
	char	*west;
	t_rgb	floor;
	t_rgb	ceiling;
}				t_wall;

// content = contents of the map file
// allocated_rows = amount of rows in the coords array
// -> (incl negative space and NULL row at end)
// map_length = length of longest row
// point_zero = bottom_l so it works like a normal coordinate system
// coords = array of coordinates
typedef struct s_map
{
	char			*content;
	int				allocated_rows;
	int				map_length;
	t_coordinates	*top_l;
	t_coordinates	*top_r;
	t_coordinates	*bottom_l;
	t_coordinates	*bottom_r;
	t_coordinates	*point_zero;
	t_coordinates	*player_start;
	t_coordinates	**coords;
}			t_map;

// win_width set to 3000 by default at the moment
// win_height set to 2000
typedef struct s_mlx
{
	void		*mlx;
	void		*mlx_window;
	void		*test;
	int			win_width;
	int			win_height;
}				t_mlx;

typedef struct s_game
{
	t_map		map;
	t_wall		walls;
	t_mlx		mlx;
	t_player	player;
	int			game_end;
}				t_game;

#endif