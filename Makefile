CC = cc

CFLAGS = -Wall -Werror -Wextra                   -g

LIBFT_DIR = libft

LDFLAGS = -L$(LIBFT_DIR) -lftprintf

NAME = push_swap

SRCS = push_swap.c

OBJS = $(SRCS:.c=.o)

LIBFT = $(LIBFT_DIR)/libftprintf.a

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(OBJS) $(LDFLAGS) -o $@

bonus: checker

$(LIBFT):
	make -C $(LIBFT_DIR) bonus

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONE: clean bonus
