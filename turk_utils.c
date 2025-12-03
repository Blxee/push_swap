/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 08:14:34 by atahiri-          #+#    #+#             */
/*   Updated: 2025/12/03 10:31:34 by atahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	bubble_sort(t_node **nodes, long len)
{
	long	i;
	long	j;
	t_node	*tmp;

	i = ~0;
	while (++i < len)
	{
		j = ~0;
		while (++j < len - i - 1)
		{
			if (nodes[j]->val > nodes[j + 1]->val)
			{
				tmp = nodes[j];
				nodes[j] = nodes[j + 1];
				nodes[j + 1] = tmp;
			}
			nodes[j]->rank = j;
			nodes[j + 1]->rank = j + 1;
		}
	}
}

static void	calculate_rank(t_swap_stack *swap)
{
	t_node	**nodes;
	long	i;

	nodes = malloc(sizeof(t_node *) * swap->b.len);
	if (!nodes)
		return (swap_stack_free(&swap), exit(0xffffffff));
	i = ~0;
	while (++i < swap->b.len)
		nodes[i] = stack_get(&swap->b, i);
	bubble_sort(nodes, swap->b.len);
	free(nodes);
}

static void	sort_3(t_swap_stack *swap)
{
	static int	i = -1;
	int			min;
	int			max;
	int			min_idx;
	int			max_idx;

	while (++i < 3)
	{
		if (i == 0 || stack_get(&swap->a, i)->val <= min)
		{
			min_idx = i;
			min = stack_get(&swap->a, i)->val;
		}
		if (i == 0 || stack_get(&swap->a, i)->val >= max)
		{
			max_idx = i;
			max = stack_get(&swap->a, i)->val;
		}
	}
	if ((max_idx + 1) % 3 == min_idx)
		sa(swap, 1);
	if (min_idx == 0)
		rra(swap, 1);
	if (min_idx && max_idx)
		ra(swap, 1);
}

static int	total_cost(t_node *node)
{
	int	total;

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

static t_node	*calculate_costs(t_swap_stack *swap)
{
	long	i;
	long	j;
	int		min_cost;
	t_node	*current;
	t_node	*min_node;

	min_cost = INT_MAX;
	i = ~0;
	while (++i < swap->b.len)
	{
		current = stack_get(&swap->b, i);
		if (i >= swap->b.len / 2)
			current->cost_b = swap->b.len - i - 1;
		else
			current->cost_b = -i - 1;
		j = ~0;
		while (++j < swap->a.len)
		{
			break;
		}
		if (total_cost(current) < min_cost)
		{
			min_cost = total_cost(current);
			min_node = current;
		}
	}
	return (min_node);
}

void	apply_turk(t_swap_stack *swap)
{
	t_node	*chosen;

	calculate_rank(swap);
	while (swap->a.len > 3)
		pb(swap, 1);
	sort_3(swap);
	while (swap->b.len > 0)
	{
		chosen = calculate_costs(swap);
		while (total_cost(chosen) > 0)
		{
			if (chosen->cost_a < 0 && chosen->cost_b < 0)
				rrr(swap, 1);
			else if (chosen->cost_a > 0 && chosen->cost_b > 0)
				rr(swap, 1);
			else
			{
				if (chosen->cost_a < 0)
					rra(swap, 1);
				else if (chosen->cost_a > 0)
					ra(swap, 1);
				if (chosen->cost_b < 0)
					rrb(swap, 1);
				else if (chosen->cost_b > 0)
					rb(swap, 1);
			}
		}
		pa(swap, 1);
	}
}
