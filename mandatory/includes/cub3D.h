/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h		                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ****** <******@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 12:33:49 by ******           #+#    #+#              */
/*   Updated: 2024/10/11 13:13:29 by ******           ###   ########.fr       */
/*                                                                           */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdbool.h>
# include "mlx/mlx.h"
# include "libft/libft.h"
# include "structs.h"
# include "functions.h"
# include "formatting.h"
# include "game.h"

//there's no such textures at the moment ofc
# define NORTH_TEXTURE "../textures/north.xpm"
# define SOUTH_TEXTURE "../textures/south.xpm"
# define WEST_TEXTURE "../textures/west.xpm"
# define EAST_TEXTURE "../textures/east.xpm"
# define TEST_XPM "textures/test.xpm"
# define TEST_HEIGHT 138
# define TEST_WIDTH 152
# define WALL_XPM "textures/wall.xpm"
# define WALL_HEIGHT 512
# define WALL_WIDTH 512
# define XK_ESCAPE 65307
# define A_KEY 97
# define D_KEY 100
# define W_KEY 119
# define S_KEY 115
# define LEFT_ARROW 65361
# define RIGHT_ARROW 65363
// # define UP_ARROW 65362
// # define DOWN_ARROW 65364

#endif