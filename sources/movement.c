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

int	ft_check_for_walls(int direction, t_coordinates **coords, \
	t_player *player)
{
	if (direction == LEFT)
	{
		if (coords[player->current->y_array][player->current->x].type == '1')
			return (print_message(1, "There's a wall.\n"));
	}
	else if (direction == RIGHT)
	{
		if (coords[player->current->y_array][player->current->x + 2].type \
			== '1')
			return (print_message(1, "There's a wall.\n"));
	}
	else if (direction == BACKWARD)
	{
		if (coords[player->current->y_array - 1][player->current->x_array].type \
			== '1')
			return (print_message(1, "There's a wall.\n"));
	}
	else if (direction == FOREWARD)
	{
		if (coords[player->current->y_array + 1][player->current->x_array].type \
			== '1')
			return (print_message(1, "There's a wall.\n"));
	}
	return (0);
}

void	ft_change_current_location(t_player *player, int direction, \
	t_coordinates **coords)
{
	t_coordinates	*temp;

	temp = player->current;
	printf("Direction: %i\n", direction);
	printf("Orientation: %i\n", player->current_orientation);
	if (direction == LEFT)
		player->current = &coords[temp->y_array][temp->x];
	else if (direction == RIGHT)
		player->current = &coords[temp->y_array][temp->x + 2];
	else if (direction == FOREWARD)
		player->current = \
			&coords[player->current->y_array + 1][player->current->x_array];
	else if (direction == BACKWARD)
		player->current = \
			&coords[player->current->y_array - 1][player->current->x_array];
	printf("New player Location: (%i|%i)\n", \
		player->current->x, player->current->y);
}

void	ft_change_current_orientation(int key, t_player *player)
{
	if (key == RIGHT_ARROW && player->current_orientation == 3)
		player->current_orientation = 0;
	else if (key == LEFT_ARROW && player->current_orientation == 0)
		player->current_orientation = 3;
	else if (key == RIGHT_ARROW && player->current_orientation != 3)
		player->current_orientation++;
	else if (key == LEFT_ARROW && player->current_orientation != 0)
		player->current_orientation--;
	printf("Current orientation: %i\n", player->current_orientation);
}
