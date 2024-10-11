/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c		                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ****** <******@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 12:33:17 by ******           #+#    #+#              */
/*   Updated: 2024/10/11 13:09:41 by ******           ###   ########.fr       */
/*                                                                           */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("Wrong number of arguments!");
		exit(1);
	}
	if (!(ft_check_extension(argv[1])))
	{
		printf("Wrong file extension!");
		exit(1);
	}
	if (argc == 2 && ft_check_extension(argv[1]))
	{
		
	}
	return (0);
}
