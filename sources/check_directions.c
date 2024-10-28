/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c		                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ****** <******@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 12:33:17 by ******           #+#    #+#              */
/*   Updated: 2024/10/11 13:09:41 by ******           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	ft_check_direction(int key, t_player *player)
{
	if ((key == KEY_W && player->current_orientation == WE) \
		|| (key == KEY_A && player->current_orientation == NO) \
		|| (key == KEY_S && player->current_orientation == EA) \
		|| (key == KEY_D && player->current_orientation == SO))
		return (LEFT);
	if ((key == KEY_S && player->current_orientation == WE) \
		|| (key == KEY_D && player->current_orientation == NO) \
		|| (key == KEY_W && player->current_orientation == EA) \
		|| (key == KEY_A && player->current_orientation == SO))
		return (RIGHT);
	if ((key == KEY_D && player->current_orientation == WE) \
		|| (key == KEY_W && player->current_orientation == NO) \
		|| (key == KEY_A && player->current_orientation == EA) \
		|| (key == KEY_S && player->current_orientation == SO))
		return (BACKWARD);
	if ((key == KEY_A && player->current_orientation == WE) \
		|| (key == KEY_S && player->current_orientation == NO) \
		|| (key == KEY_D && player->current_orientation == EA) \
		|| (key == KEY_W && player->current_orientation == SO))
		return (FOREWARD);
	return (0);
}

//the direction here tells you which way to go when the map is facing north
//so backwards is just another word for y - 1 on coordinates etc