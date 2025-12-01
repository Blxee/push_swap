/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 11:04:34 by atahiri-          #+#    #+#             */
/*   Updated: 2025/12/01 11:31:37 by atahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_swap_stack *swap)
{
	t_circular_stack	*stack;
	int					tmp;

	ft_putstr("sa\n");
	stack = &swap->a;
	if (stack->len < 2)
		return ;
	tmp = *stack_get(stack, -1);
	*(stack_get(stack, -1)) = *(stack_get(stack, -2));
	*stack_get(stack, -2) = tmp;
}

void	sb(t_swap_stack *swap)
{
	t_circular_stack	*stack;
	int					tmp;

	ft_putstr("sb\n");
	stack = &swap->b;
	if (stack->len < 2)
		return ;
	tmp = *stack_get(stack, -1);
	*(stack_get(stack, -1)) = *(stack_get(stack, -2));
	*stack_get(stack, -2) = tmp;
}

void	ss(t_swap_stack *swap)
{
	sa(swap);
	sb(swap);
}
