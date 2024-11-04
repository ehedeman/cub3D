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

// int	ft_check_direction(int key, t_player *player)
// {
// 	if ((key == W_KEY && player->current_orientation == WE) \
// 		|| (key == A_KEY && player->current_orientation == NO) \
// 		|| (key == S_KEY && player->current_orientation == EA) \
// 		|| (key == D_KEY && player->current_orientation == SO))
// 		return (LEFT);
// 	if ((key == S_KEY && player->current_orientation == WE) \
// 		|| (key == D_KEY && player->current_orientation == NO) \
// 		|| (key == W_KEY && player->current_orientation == EA) \
// 		|| (key == A_KEY && player->current_orientation == SO))
// 		return (RIGHT);
// 	if ((key == D_KEY && player->current_orientation == WE) \
// 		|| (key == W_KEY && player->current_orientation == NO) \
// 		|| (key == A_KEY && player->current_orientation == EA) \
// 		|| (key == S_KEY && player->current_orientation == SO))
// 		return (BACKWARD);
// 	if ((key == A_KEY && player->current_orientation == WE) \
// 		|| (key == S_KEY && player->current_orientation == NO) \
// 		|| (key == D_KEY && player->current_orientation == EA) \
// 		|| (key == W_KEY && player->current_orientation == SO))
// 		return (FOREWARD);
// 	return (0);
// }

//the direction here tells you which way to go when the map is facing north
//so backwards is just another word for y - 1 on coordinates etc