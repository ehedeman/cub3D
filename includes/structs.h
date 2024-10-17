/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehedeman <ehedeman@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 13:32:40 by ehedeman          #+#    #+#             */
/*   Updated: 2024/10/17 14:26:16 by ehedeman         ###   ########.fr       */
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

typedef struct s_coordinates
{
	int	x;				//just for printing
	int x_array;		//for changing locations etc
	int	y;
	int	y_array;
	int	type;
}			t_coordinates;

typedef struct s_player
{
	t_coordinates	*current;
	t_coordinates	*next;
	char			start_orientation;	//N,S,W,E, might not need it
	int				current_orientation;
	void			*mlx;
}				t_player;
//t_coordinates dont need to be freed anywhere but in map.coords

typedef struct s_wall
{
	char	*north;		//path to north wall texture
	char	*south;
	char	*east;		//if u wanna handle it differently thats cool
	char	*west;		//was just a thought of what the struct could look like
}				t_wall;

typedef struct s_map
{
	char			*content;	//content of the map file
	int				allocated_rows;
	int				map_length;	//length of longest row
	t_coordinates	*top_l;
	t_coordinates	*top_r;
	t_coordinates	*bottom_l;
	t_coordinates	*bottom_r;
	t_coordinates	*point_zero;	// = top_l makes most sense due to the way the info is read
	t_coordinates	*player_start;
	t_coordinates	**coords;	//array of coordinates
}			t_map;

typedef struct s_mlx
{
	void		*mlx;
	void		*mlx_window;
	void		*test;
	int			win_width;	//set to 3000 by default at the moment
	int			win_height;	//set to 2000
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