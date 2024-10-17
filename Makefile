# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ehedeman <ehedeman@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/11 12:32:52 by ehedeman          #+#    #+#              #
#    Updated: 2024/10/17 14:21:58 by ehedeman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	cub3D

CC				=	cc 
CFLAGS			=	-Werror -Wall -Wextra -g -fsanitize=address -fno-omit-frame-pointer

INC 			= 	-I ./includes			\
					-I ./libft				\
					-I ./mlx_linux
#sources stuff
SRC				=	main.c					\
					main_utils.c			\
					freeing_stuff.c			\
					map_parsing.c			\
					map_parsing_utils.c		\
					ft_save_map_utils.c		\
					ft_save_map.c			\
					ft_allocate_coords.c	\
					map_check.c				\
					errors.c				\
					key_handling.c			\
					ft_init_game.c			\
					movement.c				\
					check_directions.c		\
					game_utils.c
SRC_PATH		=	./sources/
SRCS			=	$(addprefix $(SRC_PATH), $(SRC))

#objects stuff
OBJ				=	$(SRC:.c=.o)
OBJ_PATH		=	./objs/
OBJS			=	$(addprefix $(OBJ_PATH), $(OBJ))

#libft stuff
LIBFT_NAME		=	libft.a
LIBFT_PATH		=	./libft/
LIBFT			=	$(LIBFT_PATH)$(LIBFT_NAME)


#minilib_x stuff
MLX_PATH		=	./mlx_linux/
MLX_NAME		=	libmlx.a
MLX 			=	$(MLX_PATH)$(MLX_NAME)

all: $(LIBFT) $(MLX) $(NAME) #norm 
	
$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) -c $< -o $@ $(INC)
	
$(LIBFT):
	@(cd $(LIBFT_PATH) && make all)
	
$(MLX):
	@(cd $(MLX_PATH) && make all)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(INC) $(LIBFT) $(MLX) -lXext -lX11 -lm

clean:
	@rm -rf $(OBJ_PATH)
	@(cd $(LIBFT_PATH) && make clean)
	@(cd $(MLX_PATH) && make clean)

fclean: clean
	@(cd $(LIBFT_PATH) && make fclean)
	@rm -f $(NAME)

re: fclean all

leaks:
	valgrind --leak-check=full \
         --show-leak-kinds=all \
         --track-origins=yes ./$(NAME) map.cub

norm:
	@norminette $(SRCS) ./includes/

.PHONY: all clean re fclean leaks norm