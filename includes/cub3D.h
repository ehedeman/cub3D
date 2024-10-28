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
# include "../mlx_linux/mlx.h"
# include "../libft/libft.h"
# include "structs.h"
# include "functions.h"
# include "formatting.h"

# define SCREEN_W 1920
# define SCREEN_H 1080

# define TEXTURE_RES    64
# define TEXTURE_NORTH	"../textures/north.xpm"
# define TEXTURE_SOUTH	"../textures/south.xpm"
# define TEXTURE_WEST	"../textures/west.xpm"
# define TEXTURE_EAST	"../textures/east.xpm"

# define EVENT_KEY_PRESS 2
# define EVENT_KEY_RELEASE 3
# define EVENT_DESTROY 17

# define MASK_KEY_PRESS 1L<<0
# define MASK_KEY_RELEASE 1L<<1

# define KEY_ESC 65307
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100

# define TEST_XPM "../textures/test.xpm"
# define TEST_HEIGHT 138
# define TEST_WIDTH 152
# define WALL_XPM "../textures/wall.xpm"
# define WALL_HEIGHT 512
# define WALL_WIDTH 512

#endif