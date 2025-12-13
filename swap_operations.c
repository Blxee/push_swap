/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 11:04:34 by atahiri-          #+#    #+#             */
/*   Updated: 2025/12/03 08:07:28 by atahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_swap_stack *swap, int show)
{
	t_circular_stack	*stack;
	t_node				tmp;

	if (!swap || !swap->a.buf)
		return ;
	if (show)
		ft_putstr_fd(1, "sa\n");
	stack = &swap->a;
	if (stack->len < 2)
		return ;
	tmp = *stack_get(stack, -1);
	*(stack_get(stack, -1)) = *(stack_get(stack, -2));
	*stack_get(stack, -2) = tmp;
}

void	sb(t_swap_stack *swap, int show)
{
	t_circular_stack	*stack;
	t_node				tmp;

	if (!swap || !swap->b.buf)
		return ;
	if (show)
		ft_putstr_fd(1, "sb\n");
	stack = &swap->b;
	if (stack->len < 2)
		return ;
	tmp = *stack_get(stack, -1);
	*(stack_get(stack, -1)) = *(stack_get(stack, -2));
	*stack_get(stack, -2) = tmp;
}

void	ss(t_swap_stack *swap, int show)
{
	if (show)
		ft_putstr_fd(1, "ss\n");
	sa(swap, 0);
	sb(swap, 0);
}
