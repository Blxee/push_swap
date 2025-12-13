/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 08:16:06 by atahiri-          #+#    #+#             */
/*   Updated: 2025/12/12 08:16:08 by atahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_min(t_swap_stack *swap)
{
	long	target_idx;
	t_node	*current;
	int		min_rank;
	long	i;

	min_rank = INT_MAX;
	target_idx = 0;
	i = ~0;
	while (swap && ++i < swap->a.len)
	{
		current = stack_get(&swap->a, i);
		if (current->rank < min_rank)
		{
			target_idx = i;
			min_rank = current->rank;
		}
	}
	return (target_idx);
}

static void	find_node_cost_a(t_swap_stack *swap, t_node *node)
{
	long	i;
	long	target_idx;
	t_node	*current;
	int		min_rank;

	min_rank = INT_MAX;
	target_idx = 0;
	i = ~0;
	while (swap && ++i < swap->a.len)
	{
		current = stack_get(&swap->a, i);
		if (current->rank > node->rank && current->rank < min_rank)
		{
			target_idx = i;
			min_rank = current->rank;
		}
	}
	if (min_rank == INT_MAX)
		target_idx = find_min(swap);
	if (target_idx >= swap->a.len / 2)
		node->cost_a = swap->a.len - target_idx - 1;
	else
		node->cost_a = -target_idx - 1;
}

t_node	*calculate_costs(t_swap_stack *swap)
{
	long	i;
	int		min_cost;
	t_node	*current;
	t_node	*min_node;

	min_cost = INT_MAX;
	i = ~0;
	while (swap && ++i < swap->b.len)
	{
		current = stack_get(&swap->b, i);
		if (i >= swap->b.len / 2)
			current->cost_b = swap->b.len - i - 1;
		else
			current->cost_b = -i - 1;
		find_node_cost_a(swap, current);
		if (total_cost(current) < min_cost)
		{
			min_cost = total_cost(current);
			min_node = current;
		}
	}
	return (min_node);
}

int	total_cost(t_node *node)
{
	int	total;

	if (!node)
		return (0);
	total = 0;
	if (node->cost_a < 0)
		total += -node->cost_a;
	else
		total += node->cost_a;
	if (node->cost_b < 0)
		total += -node->cost_b;
	else
		total += node->cost_b;
	return (total);
}
