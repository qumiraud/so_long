NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

SRC = 	src/main.c \
		src/keymap.c \
		src/parsing.c \
		src/map_list_fctn.c \
		src/handle_errors.c \
		src/ft_count_element.c \
		src/ft_flood_fill.c \


INC = includes

LIBS = libft
LIBFT = libft/libft.a
MLX_FLAGS = -Lmlx -lmlx -Lminilibx-linux -lXext -lX11
MLX_LIB = minilibx-linux/libmlx_linux.a

OBJ_DIR = obj
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:src/%.c=%.o))

all: $(LIBFT) $(MLX_LIB) $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(MLX_LIB)
	@clear && echo "SO_LONG is ready"
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(MLX_FLAGS) -L./libft -lft

$(OBJ_DIR)/%.o: src/%.c | $(OBJ_DIR)
	@echo "Compiling $(notdir $<)..."
	@$(CC) $(CFLAGS) -I. -I$(INC) -Ilibft/ -Iminilibx-linux/ -o $@ -c $<

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(LIBFT):
	@echo "Building libft..."
	@$(MAKE) -C libft

$(MLX_LIB):
	@echo "Building MiniLibX..."
	@$(MAKE) -C minilibx-linux

clean:
	@echo "Cleaning object files..."
	@rm -rf $(OBJ_DIR)

fclean: clean
	@echo "Cleaning libraries and executable..."
	@$(MAKE) -C libft fclean
	@$(MAKE) -C minilibx-linux clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

# NAME = so_long

# CC = cc
# CFLAGS = -Wall -Wextra -Werror -g

# SRC = src/main.c

# OBJ_D = obj
# OBJ = $(SRCS:%.c=$(OBJ_DIR)/%.o)

# INC = includes

# LIBS = libft
# LIBFT = libft/libft.a
# MLX_FLAGS = -Lmlx -lmlx -Lminilibx-linux -lXext -lX11
# MLX_LIB = minilibx-linux/libmlx_linux.a

# SRCS = src/main.c \
# 		\

# all: $(LIBFT) $(MLX_LIB) $(NAME)

# $(NAME): $(OBJ) $(LIBFT) $(MLX_LIB)
# 	@echo "Linking $(NAME)..."
# 	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(MLX_FLAGS) -L./libft -lft

# $(OBJ_D):
# 	@mkdir -p $(OBJ_D)

# $(OBJ_DIR)/%.o: %.c
# 	@echo "Compiling $(notdir $<)..."
# 	@$(CC) $(CFLAGS) -I. -I$(INC) -I LIBFT/ -I minilibx-linux/ -o $@ -c $<

# $(LIBFT):
# 	@echo "Building libft..."
# 	@$(MAKE) -C libft

# $(MLX_LIB):
# 	@echo "Building MiniLibX..."
# 	@$(MAKE) -C minilibx-linux

# clean:
# 	@echo "Cleaning object files..."
# 	@rm -rf $(OBJ_DIR)

# fclean: clean
# 	echo "Cleaning libraries and executable..."
# 	@$(MAKE) -C libft fclean
# 	@$(MAKE) -C minilibx-linux clean
# 	@rm -f $(NAME)

# re: fclean all

# .PHONY: all clean fclean re