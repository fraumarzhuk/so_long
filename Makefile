NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror -g -I$(LIBFT_DIR) -I$(MLX_DIR) -I$(GNL_DIR)
MLXFLAGS = -framework OpenGL -framework AppKit
LIBFT_DIR = ./libft
MLX_DIR = ./mlx
GNL_DIR = ./gnl
LIBS = -L$(LIBFT_DIR) -lft -L$(MLX_DIR) -lmlx

# Source files
SRCS = main.c
OBJS = $(SRCS:.c=.o)

# 'all' target
all: $(NAME)

# 'libft' target
libft:
	$(MAKE) -C $(LIBFT_DIR)

# 'gnl' target
gnl:
	$(MAKE) -C $(GNL_DIR)

# 'so_long' target
$(NAME): libft gnl $(OBJS)
	$(CC) $(CFLAGS) $(MLXFLAGS) $(OBJS) $(LIBS) -o $(NAME)

# Pattern rule for object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# 'clean' target
clean:
	$(MAKE) -C $(LIBFT_DIR) clean
#$(MAKE) -C $(MLX_DIR) clean
	$(MAKE) -C $(GNL_DIR) clean
	rm -f $(OBJS)

# 'fclean' target
fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

# 're' target
re: fclean all

# Declare phony targets
.PHONY: all libft gnl clean fclean re
