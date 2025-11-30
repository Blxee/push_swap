CC = cc

CFLAGS = -Wall -Werror -Wextra                   -g

NAME = push_swap

SRCS = push_swap.c ft_atoi.c ft_split.c ft_isspace.c

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(OBJS) -o $@

bonus: checker

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONE: clean bonus
