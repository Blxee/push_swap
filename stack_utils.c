/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 11:02:20 by atahiri-          #+#    #+#             */
/*   Updated: 2025/12/02 18:39:15 by atahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*stack_get(t_circular_stack *stack, long idx)
{
	idx += stack->start;
	while (idx < 0)
		idx += stack->len;
	idx %= stack->len;
	return (&stack->buf[idx]);
}

void	stack_push_back(t_circular_stack *stack, t_node val)
{
	long	i;

	if (!stack)
		return ;
	i = stack->len;
	while (i > stack->start)
	{
		stack->buf[i] = stack->buf[i - 1];
		i--;
	}
	(stack->len)++;
	stack->buf[stack->start++] = val;
}

void	stack_push_front(t_circular_stack *stack, t_node val)
{
	long	i;

	if (!stack)
		return ;
	i = stack->len;
	while (i > stack->start)
	{
		stack->buf[i] = stack->buf[i - 1];
		i--;
	}
	(stack->len)++;
	stack->buf[stack->start] = val;
}

t_node	stack_pop(t_circular_stack *stack)
{
	long	i;
	t_node	val;

	if (!stack || stack->len == 0)
		return ((t_node){});
	val = *stack_get(stack, -1);
	i = 0;
	while (i < stack->len - stack->start)
	{
		if (stack->start == 0 && i == 0)
			stack->buf[stack->len - 1] = stack->buf[0];
		else
			stack->buf[stack->start + i - 1] = stack->buf[stack->start + i];
		i++;
	}
	(stack->len)--;
	(stack->start)--;
	if (stack->start < 0)
		stack->start = stack->len - 1;
	return (val);
}

int	stack_sorted(t_circular_stack *stack)
{
	long	i;

	if (!stack || stack->len <= 0)
		return (0);
	i = 0;
	while (i < stack->len - 1)
	{
		if (stack_get(stack, i)->val < stack_get(stack, i + 1)->val)
			return (0);
		i++;
	}
	return (1);
}
