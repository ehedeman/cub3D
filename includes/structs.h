/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehedeman <ehedeman@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 13:32:40 by ehedeman          #+#    #+#             */
/*   Updated: 2024/10/15 15:14:52 by ehedeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

typedef struct s_coordinates
{
	int	x;
	int	y;
	int	type;
}			t_coordinates;

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
	t_coordinates	**coords;	//array of coordinates
}			t_map;

typedef	struct	s_game
{
	t_map	map;
}				t_game;