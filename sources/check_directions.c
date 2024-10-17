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
	if (key == W_KEY && player->current_orientation == NO)
		return (FOREWARD);
	if (key == S_KEY && player->current_orientation == NO)
		return (BACKWARD);
	if (key == A_KEY && player->current_orientation == NO)
		return (LEFT);
	if (key == D_KEY && player->current_orientation == NO)
		return (RIGHT);	//correct and works
	
	if (key == W_KEY && player->current_orientation == EA)
		return (RIGHT);
	if (key == S_KEY && player->current_orientation == EA)
		return (LEFT);
	if (key == A_KEY && player->current_orientation == EA)
		return (FOREWARD);
	if (key == D_KEY && player->current_orientation == EA)
		return (BACKWARD); //correct and works

	if (key == W_KEY && player->current_orientation == SO)
		return (BACKWARD);
	if (key == S_KEY && player->current_orientation == SO)
		return (FOREWARD);
	if (key == A_KEY && player->current_orientation == SO)
		return (RIGHT);
	if (key == D_KEY && player->current_orientation == SO)
		return (LEFT); // correct and works

	if (key == W_KEY && player->current_orientation == WE)
		return (LEFT);
	if (key == S_KEY && player->current_orientation == WE)
		return (RIGHT);
	if (key == A_KEY && player->current_orientation == WE)
		return (BACKWARD);
	if (key == D_KEY && player->current_orientation == WE)
		return (FOREWARD);
	return (0);
}	//output is correct
