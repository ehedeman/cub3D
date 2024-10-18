/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save_args_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehedeman <ehedeman@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:49:30 by svalchuk          #+#    #+#             */
/*   Updated: 2024/10/18 11:08:10 by ehedeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

bool	ft_check_args(t_game *game)
{
	if (!game->walls.north || !game->walls.south || !game->walls.east
		|| !game->walls.west)
		return (true);
	return (false);
}
