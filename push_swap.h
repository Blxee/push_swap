/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 17:53:27 by atahiri-          #+#    #+#             */
/*   Updated: 2025/12/01 14:28:21 by atahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_cicular_stack
{
	int					*buf;
	long				capacity;
	long				start;
	long				len;
}						t_circular_stack;

typedef struct s_swap_stack
{
	t_circular_stack	a;
	t_circular_stack	b;
}						t_swap_stack;

typedef void			(*t_operation)(t_swap_stack *swap, int show);

// swap_stack methods
t_swap_stack			*swap_stack_new(long num_size);
void					swap_stack_free(t_swap_stack **swap);

// stack methods
int						*stack_get(t_circular_stack *stack, long idx);
void					stack_push_back(t_circular_stack *stack, int val);
void					stack_push_front(t_circular_stack *stack, int val);
int						stack_pop(t_circular_stack *stack);
int						stack_sorted(t_circular_stack *stack);

// parsing utils
long					count_args(int argc, char **argv);
void					parse_args(t_swap_stack *swap, int argc, char **arpv);
int						ft_isspace(int c);
char					**ft_split(char const *s);
int						ft_atoi(const char *nptr, int *fail);
void					ft_putstr_fd(const int fd, const char *str);
int						is_number_repeated(t_circular_stack *stack);

// push swap operations
void					sa(t_swap_stack *swap, int show);
void					sb(t_swap_stack *swap, int show);
void					ss(t_swap_stack *swap, int show);
void					pa(t_swap_stack *swap, int show);
void					pb(t_swap_stack *swap, int show);
void					ra(t_swap_stack *swap, int show);
void					rb(t_swap_stack *swap, int show);
void					rr(t_swap_stack *swap, int show);
void					rra(t_swap_stack *swap, int show);
void					rrb(t_swap_stack *swap, int show);
void					rrr(t_swap_stack *swap, int show);

#endif
