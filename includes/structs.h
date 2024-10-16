/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehedeman <ehedeman@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 13:32:40 by ehedeman          #+#    #+#             */
/*   Updated: 2024/10/16 13:19:07 by ehedeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

typedef struct s_coordinates
{
	int	x;
	int	y;
	int	type;
}			t_coordinates;

typedef struct s_player
{
	t_coordinates	*current;
	t_coordinates	*next;
	char			current_orientation;	//N,S,W,E, might not need it
	void			*mlx;	//add more if we 
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

typedef struct s_game
{
	t_map		map;
	t_wall		walls;
	t_player	player;
	void		*mlx;
	void		*mlx_window;
	int			win_width;	//set to 3000 by default at the moment
	int			win_height;	//set to 2000
	void		*test;
	int			game_end;
}				t_game;