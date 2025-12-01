/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 17:53:27 by atahiri-          #+#    #+#             */
/*   Updated: 2025/12/01 08:37:39 by atahiri-         ###   ########.fr       */
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

typedef void			(*t_operation)(t_swap_stack *swap);

t_swap_stack			*swap_stack_new(long num_size);
t_swap_stack			**get_swap_stacks(void);
void					swap_stack_free(t_swap_stack **swap);

int						*stack_get(t_circular_stack *stack, long idx);
void					stack_push_back(t_circular_stack *stack, int val);
void					stack_push_front(t_circular_stack *stack, int val);
int						stack_pop(t_circular_stack *stack);

int						ft_isspace(int c);
char					**ft_split(char const *s);
int						ft_atoi(const char *nptr, int *fail);
void					ft_putstr(const char *str);
int						is_number_repeated(t_circular_stack *stack);

void					sa(t_swap_stack *swap);
void					sb(t_swap_stack *swap);
void					ss(t_swap_stack *swap);
void					pa(t_swap_stack *swap);
void					pb(t_swap_stack *swap);
void					ra(t_swap_stack *swap);
void					rb(t_swap_stack *swap);
void					rr(t_swap_stack *swap);
void					rra(t_swap_stack *swap);
void					rrb(t_swap_stack *swap);
void					rrr(t_swap_stack *swap);

#endif
