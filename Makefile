CC = cc

CFLAGS = -Wall -Werror -Wextra                   -g

NAME = push_swap

PUSH_SWAP_SRCS = push_swap.c ft_atoi.c ft_isspace.c ft_putstr_fd.c \
				 ft_split.c is_number_repeated.c parse_args.c turk_utils.c \
				 push_operations.c count_args.c reverse_rotate_operations.c \
				 rotate_operations.c stack_utils.c swap_operations.c swap_stack_utils.c

PUSH_SWAP_OBJS = $(PUSH_SWAP_SRCS:.c=.o)

BONUS_NAME = checker

CHECKER_SRCS = checker.c  push_operations.c reverse_rotate_operations.c \
			   rotate_operations.c swap_operations.c stack_utils.c \
			   swap_stack_utils.c ft_putstr_fd.c count_args.c parse_args.c \
			   ft_isspace.c is_number_repeated.c ft_split.c ft_atoi.c

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
