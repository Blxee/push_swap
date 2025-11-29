/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 17:53:27 by atahiri-          #+#    #+#             */
/*   Updated: 2025/11/29 14:02:57 by atahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_cicular_stack 
{
  int     *buf;
  size_t	capacity;
  size_t	start;
  size_t	len;
} t_cicular_stack;

typedef struct s_swap_stack {
  t_cicular_stack a;
  t_cicular_stack b;
} t_swap_stack;

typedef void (*t_operation)(t_swap_stack *swap);

t_swap_stack  *swap_stack_new(size_t num_size);
void	        swap_stack_free(t_swap_stack *swap);

int   *stack_get(t_cicular_stack *stack, size_t idx);
void  stack_push(t_cicular_stack *stack, int val);
int   stack_pop(t_cicular_stack *stack);
 
int   ft_atoi(char *str, int *fail);
void  ft_putstr(const char *str);

void  apply_op(t_swap_stack *swap, t_operation op);

void	sa(t_swap_stack *swap);
void	sb(t_swap_stack *swap);
void	ss(t_swap_stack *swap);
void	pa(t_swap_stack *swap);
void	pb(t_swap_stack *swap);
void	ra(t_swap_stack *swap);
void	rb(t_swap_stack *swap);
void	rr(t_swap_stack *swap);
void	rra(t_swap_stack *swap);
void	rrb(t_swap_stack *swap);
void	rrr(t_swap_stack *swap);

#endif
