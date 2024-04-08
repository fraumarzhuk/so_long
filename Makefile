NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror -g -I$(LIBFT_DIR)
LIBFT_DIR = ./libft
LIBS = -L$(LIBFT_DIR) -lft

# Source files for pushswap
SRCS = main.c
OBJS = $(SRCS:.c=.o)

# 'all' target
all: $(NAME)

$(NAME): libft $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

# Compile libft
libft:
	$(MAKE) -C $(LIBFT_DIR)

# Pattern rule for object files
%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

# 'clean' rule
clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJS)

# 'fclean' rule
fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

# 're' rule
re: fclean all

# Declare phony targets
.PHONY: all libft clean fclean re
