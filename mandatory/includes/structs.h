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
	float	x;
	float	y;
	int		type;
	float	x;
	float	y;
	int		type;
}			t_coordinates;

// start->orientation = N, S, W, E, might not need it
typedef struct s_player
{
	float			x;
	float			y;
	float 			angle;

	t_coordinates	start;
	bool key_up;
	bool key_down;
	bool key_left;
	bool key_right;

	bool left_rotate;
	bool right_rotate;
	float			x;
	float			y;
	float 			angle;

	t_coordinates	start;
	bool key_up;
	bool key_down;
	bool key_left;
	bool key_right;

	bool left_rotate;
	bool right_rotate;
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
	t_coordinates	**coords;		//for checking of map
	char	**coordinates;	//for actual game
	int				length;
	int				width;
	t_coordinates	**coords;		//for checking of map
	char	**coordinates;	//for actual game
	int				length;
	int				width;
	t_coordinates	*top_l;
	t_coordinates	*top_r;
	t_coordinates	*bottom_l;
	t_coordinates	*bottom_r;
	t_coordinates	*point_zero;
	t_coordinates	*player_start;
}			t_map;

// win_width set to 3000 by default at the moment
// win_height set to 2000
typedef struct s_mlx
{
	void		*mlx;
	void		*mlx_window;
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
	void *win;
	void *img;

	char *data;
	int bpp;
	int size_line;
	int endian;
	char	**map_array;
	void *win;
	void *img;

	char *data;
	int bpp;
	int size_line;
	int endian;
	char	**map_array;
}				t_game;

#endif