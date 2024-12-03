/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ****.h		                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ****** <******@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 12:33:17 by ******           #+#    #+#              */
/*   Updated: 2024/10/11 13:09:41 by ******           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdbool.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <X11/X.h>

# include "libft/libft.h"
# include "mlx/mlx.h"

# include "formatting.h"
# include "functions.h"
# include "structs.h"

# define DEBUG 0

# define WIDTH 1280
# define HEIGHT 720
# define BLOCK    64

# define TEXTURE_NORTH	"../textures/north.xpm"
# define TEXTURE_SOUTH	"../textures/south.xpm"
# define TEXTURE_WEST	"../textures/west.xpm"
# define TEXTURE_EAST	"../textures/east.xpm"

# define PI 3.14159265359

# define KEY_ESC 65307
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100

# define TEST_XPM "../assets/test.xpm"
# define TEST_HEIGHT 138
# define TEST_WIDTH 152
# define WALL_XPM "../assets/wall.xpm"
# define WALL_HEIGHT 512
# define WALL_WIDTH 512

# ifndef BONUS
#  define IS_BONUS 1
# endif

#endif