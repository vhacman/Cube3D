# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vhacman <vhacman@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/05 21:12:49 by vhacman           #+#    #+#              #
#    Updated: 2026/03/05 21:12:49 by vhacman          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                                VARIABLES                                     #
# **************************************************************************** #

NAME        = cub3D
CC          = cc
CFLAGS      = -Wall -Wextra -Werror
RM          = rm -f
MAKEFLAGS   += -s

# Directories
SRC_DIR     = src
OBJ_DIR     = obj
INC_DIR     = include
LIBFT_DIR   = libft

# Library
LIBFT       = $(LIBFT_DIR)/libft.a

# MiniLibX (Linux)
MLX_DIR     = minilibx-linux
MLX         = $(MLX_DIR)/libmlx.a
MLX_FLAGS = -L$(MLX_DIR) -lmlx_Linux -lXext -lX11 -lm //aggiunto -lmlx_Linux, solo -lmlx non compilava

# Sources
SRCS        = $(SRC_DIR)/main.c \
              $(SRC_DIR)/parser/parse_file.c \
              $(SRC_DIR)/parser/parse_map.c \
              $(SRC_DIR)/parser/parse_textures.c \
              $(SRC_DIR)/parser/parse_colors.c \
              $(SRC_DIR)/parser/validate_map.c \
              $(SRC_DIR)/raycaster/raycaster.c \
              $(SRC_DIR)/raycaster/dda.c \
              $(SRC_DIR)/raycaster/player_move.c \
              $(SRC_DIR)/render/render.c \
              $(SRC_DIR)/render/draw_walls.c \
              $(SRC_DIR)/render/draw_floor_ceiling.c \
              $(SRC_DIR)/render/textures.c \
              $(SRC_DIR)/render/sprites.c \
              $(SRC_DIR)/events/events.c \
              $(SRC_DIR)/events/keys.c \
              $(SRC_DIR)/utils/utils.c \
              $(SRC_DIR)/utils/error.c \
              $(SRC_DIR)/utils/free.c

OBJS        = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

# Bonus sources
SRCS_BONUS  = $(SRCS) \
              $(SRC_DIR)/bonus/minimap_bonus.c \
              $(SRC_DIR)/bonus/doors_bonus.c \
              $(SRC_DIR)/bonus/sprites_anim_bonus.c \
              $(SRC_DIR)/bonus/mouse_bonus.c

OBJS_BONUS  = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS_BONUS))

# **************************************************************************** #
#                                  RULES                                       #
# **************************************************************************** #

all: $(LIBFT) $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -I$(INC_DIR) -I$(LIBFT_DIR)/includes \
		-L$(LIBFT_DIR) -lft $(MLX_FLAGS) -o $(NAME)
	@echo "✅ $(NAME) compiled successfully."

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -I$(INC_DIR) -I$(LIBFT_DIR)/includes -I$(MLX_DIR) -c $< -o $@ //aggiunto ultima parte per far funzionare minilibx

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

bonus: $(LIBFT) $(OBJS_BONUS)
	@$(CC) $(CFLAGS) $(OBJS_BONUS) -I$(INC_DIR) -I$(LIBFT_DIR)/includes \
		-L$(LIBFT_DIR) -lft $(MLX_FLAGS) -o $(NAME)
	@echo "✅ $(NAME) with bonuses compiled successfully."

clean:
	@$(RM) -rf $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@echo "🧽 Object files cleaned."

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@echo "💀 $(NAME) and libft removed."

re: fclean all

.PHONY: all bonus clean fclean re
