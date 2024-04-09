NAME = gnl.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I.

SRCS = get_next_line_bonus.c \
		get_next_line_utils_bonus.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c get_next_line_bonus.h
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re