/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ****.c		                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ****** <******@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 12:33:17 by ******           #+#    #+#              */
/*   Updated: 2024/10/11 13:09:41 by ******           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	ft_err_exit(char *str)
{
	ft_printf(RED"\n  ERROR » "RESET BLUE"%s\n\n"RESET, str);
	exit(EXIT_FAILURE);
}

void	ft_err_map(char *str, t_game *game)
{
	ft_free_map(game, 1);
	ft_err_exit(str);
}

void	ft_err_game(char *str, t_game *game)
{
	ft_free_game(game);
	ft_free_map(game, 1);
	ft_err_exit(str);
}

void	print_error(char *str, t_game *game, int mode)
{
	printf("%s\n", str);
	// while (*str)
	// 	write(mode, str++, 1);
	ft_free_map(game, 1);
	ft_free_game(game);
	exit(mode);
}
