/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 08:14:34 by atahiri-          #+#    #+#             */
/*   Updated: 2025/12/07 10:41:38 by atahiri-         ###   ########.fr       */
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
		}
	}
	i = ~0;
	while (++i < len)
		nodes[i]->rank = i;
}

static void	calculate_rank(t_swap_stack *swap)
{
	t_node	**nodes;
	long	i;

	nodes = malloc(sizeof(t_node *) * swap->a.len);
	if (!nodes)
		return (swap_stack_free(&swap), exit(-1));
	i = ~0;
	while (++i < swap->a.len)
		nodes[i] = stack_get(&swap->a, i);
	bubble_sort(nodes, swap->a.len);
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

static void	find_node_cost_a(t_swap_stack *swap, t_node *node)
{
	long	i;
	long	target_idx;
	t_node	*current;
	int		min_rank;

	min_rank = INT_MAX;
	target_idx = 0;
	i = ~0;
	while (++i < swap->a.len)
	{
		current = stack_get(&swap->a, i);
		if (current->rank > node->rank && current->rank < min_rank)
		{
			target_idx = i;
			min_rank = current->rank;
		}
	}
	if (min_rank == INT_MAX)
	{
		i = ~0;
		while (++i < swap->a.len)
		{
			current = stack_get(&swap->a, i);
			if (current->rank < min_rank)
			{
				target_idx = i;
				min_rank = current->rank;
			}
		}
	}
	if (target_idx >= swap->a.len / 2)
		node->cost_a = swap->a.len - target_idx - 1;
	else
		node->cost_a = -target_idx - 1;
}

static t_node	*calculate_costs(t_swap_stack *swap)
{
	long	i;
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
		find_node_cost_a(swap, current);
		if (total_cost(current) < min_cost)
		{
			min_cost = total_cost(current);
			min_node = current;
		}
	}
	return (min_node);
}

static void	prepare_rotate(t_swap_stack *swap, t_node *tg)
{
	while (total_cost(tg) > 0)
	{
		if (tg->cost_a < 0 && tg->cost_b < 0)
			rrr(swap, 1);
		else if (tg->cost_a > 0 && tg->cost_b > 0)
			rr(swap, 1);
		else
		{
			if (tg->cost_a < 0)
				rra(swap, 1);
			else if (tg->cost_a > 0)
				ra(swap, 1);
			if (tg->cost_b < 0)
				rrb(swap, 1);
			else if (tg->cost_b > 0)
				rb(swap, 1);
		}
		tg->cost_a += (tg->cost_a < 0) * 1 + (tg->cost_a > 0) * -1;
		tg->cost_b += (tg->cost_b < 0) * 1 + (tg->cost_b > 0) * -1;
	}
}

void	leave_lis(t_swap_stack *swap)
{
	long	idx;
	long	len;
	long	top_idx;
	long	top_len;
	long	i;

	i = ~0;
	top_len = 0;
	while (++i < swap->a.len)
	{
		if (i == 0 || stack_get(&swap->a, i - 1)->rank < stack_get(&swap->a, i)->rank)
		{
			idx = i;
			len = 0;
		}
		if (++len > top_len)
		{
			top_idx = idx;
			top_len = len;
		}
	}
	while (swap->a.len > 3 && swap->a.len > top_idx + top_len)
		pb(swap, 1);
	while (swap->a.len > 3 && top_idx-- > 0)
		rra(swap, 1), pb(swap, 1);
	if (swap->a.len == 3)
		sort_3(swap);
}

#include <stdio.h>
void	print_stack(t_circular_stack *stack);

void	apply_turk(t_swap_stack *swap)
{
	t_node	*tg;

	calculate_rank(swap);
	// print_stack(&swap->a);
	// print_stack(&swap->b);
	leave_lis(swap);
	// if (swap->a.len == 3)
	// 	sort_3(swap);
	// print_stack(&swap->a);
	// print_stack(&swap->b);
	while (swap->b.len > 0)
	{
		tg = calculate_costs(swap);
		prepare_rotate(swap, tg);
		pa(swap, 1);
	}
	// return ;
	while (1)
	{
		tg = stack_get(&swap->a, -1);
		if (tg->rank == 0)
			break ;
		if (tg->rank > swap->a.len / 2)
			ra(swap, 1);
		else
			rra(swap, 1);
	}
}
