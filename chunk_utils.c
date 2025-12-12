/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 08:16:14 by atahiri-          #+#    #+#             */
/*   Updated: 2025/12/12 08:16:16 by atahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	find_chunk_member(t_circular_stack *stack, int c_size, int c_i)
{
	t_node	*node;
	int		top;
	int		bottom;

	top = 0;
	while (1)
	{
		if (-(--top) > stack->len)
			return (999999);
		node = stack_get(stack, top);
		if (node->rank >= (c_size * c_i) && node->rank < (c_size * (c_i + 1)))
			break ;
	}
	top++;
	bottom = -1;
	while (1)
	{
		if (++bottom >= stack->len)
			return (999999);
		node = stack_get(stack, bottom);
		if (node->rank >= (c_size * c_i) && node->rank < (c_size * (c_i + 1)))
			break ;
	}
	bottom++;
	return ((-top >= bottom) * bottom + (-top < bottom) * top);
}

void	push_chunks(t_swap_stack *swap)
{
	long	target;
	int		chunk_size;
	int		chunk_idx;

	chunk_size = 100;
	chunk_idx = 0;
	while (swap->a.len > 3)
	{
		target = find_chunk_member(&swap->a, chunk_size, chunk_idx);
		while (target)
		{
			if (target > 0)
				rra(swap, 1);
			else
				ra(swap, 1);
			target += (target > 0) * -1 + (target < 0) * 1;
		}
		pb(swap, 1);
		if (stack_get(&swap->b, -1)->rank < swap->b.len)
			rb(swap, 1);
		chunk_idx = swap->b.len / chunk_size;
	}
}
