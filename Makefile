NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror -g -I$(LIBFT_DIR) -I$(MLX_DIR) -I$(GNL_DIR) -fsanitize=address
MLXFLAGS = -framework OpenGL -framework AppKit
LIBFT_DIR = ./libft
MLX_DIR = ./mlx
GNL_DIR = ./gnl
LIBS = -L$(LIBFT_DIR) -lft -L$(MLX_DIR) -lmlx
RED=\033[0;31m
GREEN=\033[0;32m
YELLOW=\033[0;33m
NC=\033[0m # No Color

# Source files
SRCS = main.c parsing.c errors.c ./gnl/get_next_line_bonus.c ./gnl/get_next_line_utils_bonus.c rendering.c render_player.c events.c locate.c utils.c
OBJS = $(SRCS:.c=.o)

# 'all' target
all: $(NAME)

# 'libft' target
libft:
	@$(MAKE) -C $(LIBFT_DIR) >/dev/null

# 'so_long' target
$(NAME): libft gnl $(OBJS)
	@$(CC) $(CFLAGS) $(MLXFLAGS) $(OBJS) $(LIBS) -o $(NAME) >/dev/null
	@echo "${GREEN}💅 Compiled successfully! 💅${NC}"

# Pattern rule for object files
%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@ >/dev/null

# 'clean' target
clean:
	@$(MAKE) -C $(LIBFT_DIR) clean >/dev/null
	@rm -f $(OBJS) >/dev/null

# 'fclean' target
fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean >/dev/null
	@rm -f $(NAME) >/dev/null
	@echo "${YELLOW}🧼 All files cleaned. 🧼${NC}"

# 're' target
re: fclean all

# Declare phony targets
.PHONY: all libft gnl clean fclean re
