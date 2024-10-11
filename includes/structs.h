/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehedeman <ehedeman@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 13:32:40 by ehedeman          #+#    #+#             */
/*   Updated: 2024/10/11 13:44:30 by ehedeman         ###   ########.fr       */
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
	t_coordinates	top_l;
	t_coordinates	top_r;
	t_coordinates	bottom_l;
	t_coordinates	bottom_r;
	t_coordinates	point_zero;	// = bottom_r makes most sense
}			t_map;
