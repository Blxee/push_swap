CC = cc

CFLAGS = -Wall -Werror -Wextra                   -g

NAME = push_swap

PUSH_SWAP_SRCS = count_args.c ft_atoi.c ft_isspace.c ft_putstr.c \
	   ft_split.c is_number_repeated.c parse_args.c \
	   push_operations.c push_swap.c reverse_rotate_operations.c \
	   rotate_operations.c stack_utils.c swap_operations.c swap_stack_utils.c

PUSH_SWAP_OBJS = $(PUSH_SWAP_SRCS:.c=.o)

BONUS_NAME = checker
CHECKER_SRCS =

CHECKER_OBJS = $(CHECKER_SRCS:.c=.o)

$(NAME): $(PUSH_SWAP_OBJS)
	$(CC) $(PUSH_SWAP_OBJS) -o $@

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(CHECKER_OBJS)
	$(CC) $(CHECKER_OBJS) -o $@

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

clean:
	rm -f $(PUSH_SWAP_OBJS) $(CHECKER_OBJS)

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

.PHONE: clean bonus
