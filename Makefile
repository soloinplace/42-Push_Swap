CC	= cc
CFLAGS	= -Wall -Wextra -Werror
NAME	= push_swap
SRCS	= pushswap.c error.c	ft_printf.c	ft_print.c	complex.c	operation.c	flag.c	simple.c	init.c	medium.c	bench.c
OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re