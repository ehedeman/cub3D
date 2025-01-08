NAME = ../cub3D_bonus

SRC_DIR = src
SRC =	$(SRC_DIR)/main.c \
		$(SRC_DIR)/engine/bonus_related.c \
		$(SRC_DIR)/engine/color.c \
		$(SRC_DIR)/engine/crash_avoiding.c \
		$(SRC_DIR)/engine/render_utils.c \
		$(SRC_DIR)/engine/render.c \
		$(SRC_DIR)/game/game.c \
		$(SRC_DIR)/game/init_game.c \
		$(SRC_DIR)/map/ft_allocate_coords.c \
		$(SRC_DIR)/map/ft_convert_map.c \
		$(SRC_DIR)/map/ft_save_args_utils.c \
		$(SRC_DIR)/map/ft_save_args.c \
		$(SRC_DIR)/map/ft_save_map_utils.c \
		$(SRC_DIR)/map/ft_save_map.c \
		$(SRC_DIR)/map/map_check.c \
		$(SRC_DIR)/map/map_parsing_utils.c \
		$(SRC_DIR)/map/map_parsing.c \
		$(SRC_DIR)/map/minimap.c \
		$(SRC_DIR)/player/move_player.c \
		$(SRC_DIR)/player/player_utils.c \
		$(SRC_DIR)/player/player.c \
		$(SRC_DIR)/utils/errors.c \
		$(SRC_DIR)/utils/free_utils.c \
		$(SRC_DIR)/utils/free.c \
		$(SRC_DIR)/utils/ft_debug.c \
		$(SRC_DIR)/utils/print.c

INCLUDES_DIR = includes

# Compiler and Flags
CC = cc

CFLAGS = -g -O3
CFLAGS += -Wall -Wextra -Werror

CFLAGS += -I$(LIBFT_DIR) -I$(INCLUDES_DIR)
LDFLAGS += -L./$(INCLUDES_DIR)/mlx -lmlx -lXext -lX11 -lm -lz 

DEBUG 		= 0
FSANITIZE 	= 1

ifeq ($(DEBUG), 1)
    CFLAGS += -DDEBUG=1
endif

ifeq ($(FSANITIZE), 1)
    CFLAGS += -fsanitize=address -fno-omit-frame-pointer
endif

LIBFT_DIR = ./$(INCLUDES_DIR)/libft/
LIBFT = $(LIBFT_DIR)/libft.a
LDLIBS = -L$(LIBFT_DIR) -lft

OBJ_DIR = .obj
OBJ = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS)$(OBJ) -o $(NAME) $(LDLIBS) $(LDFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(LIBFT)
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR) DEBUG=$(DEBUG) FSANITIZE=$(FSANITIZE)
	
clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)

re: fclean
	$(MAKE) all

# ===== Utils =====
v: $(NAME)
	valgrind --leak-check=full ./$(NAME) map.cub

mlx:
	git clone https://github.com/42Paris/minilibx-linux.git ./$(INCLUDES_DIR)/mlx; \
	make -C ./$(INCLUDES_DIR)/mlx
	
.PHONY: all clean fclean re run v


# find . -path './includes/mlx' -prune -o -type f -print | xargs norminette