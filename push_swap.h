/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 17:53:27 by atahiri-          #+#    #+#             */
/*   Updated: 2025/11/28 10:56:55 by blxee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_stack {
  int val;
  struct s_stack *prev;
  struct s_stack *next;
} t_stack;

typedef struct s_swap_stack {
  t_stack *a;
  t_stack *b;
} t_swap_stack;

int	ft_atoi(char *str, int *fail);

void	stack_add_front(t_stack **stack, int val);
void	stack_add_back(t_stack **stack, int val);
void	stack_delete(t_stack **stack);

t_swap_stack	*swap_stack_new(void);
void	swap_stack_free(t_swap_stack *stacks);

void	sa(t_swap_stack *stacks);
void	sb(t_swap_stack *stacks);
void	ss(t_swap_stack *stacks);
void	pa(t_swap_stack *stacks);
void	pb(t_swap_stack *stacks);
void	ra(t_swap_stack *stacks);
void	rb(t_swap_stack *stacks);
void	rr(t_swap_stack *stacks);
void	rra(t_swap_stack *stacks);
void	rrb(t_swap_stack *stacks);
void	rrr(t_swap_stack *stacks);

#endif
