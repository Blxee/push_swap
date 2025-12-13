/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 08:14:34 by atahiri-          #+#    #+#             */
/*   Updated: 2025/12/12 08:14:34 by atahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	bubble_sort(t_node **nodes, long len)
{
	long	i;
	long	j;
	t_node	*tmp;

	i = ~0;
	while (nodes && ++i < len)
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
	long	i;

	if (!swap)
		return ;
	swap->ranked = malloc(sizeof(t_node *) * swap->a.len);
	if (!swap->ranked)
		return (swap_stack_free(&swap), exit(-1));
	i = ~0;
	while (++i < swap->a.len)
		swap->ranked[i] = stack_get(&swap->a, i);
	bubble_sort(swap->ranked, swap->a.len);
}

static void	sort_3(t_swap_stack *swap)
{
	static int	i = -1;
	int			min;
	int			max;
	int			min_idx;
	int			max_idx;

	while (swap && ++i < 3)
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

static void	prepare_rotate(t_swap_stack *swap, t_node *tg)
{
	while (swap && tg && total_cost(tg) > 0)
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

void	apply_turk(t_swap_stack *swap)
{
	t_node	*tg;

	if (!swap || stack_sorted(&swap->a))
		return ;
	calculate_rank(swap);
	push_chunks(swap);
	sort_3(swap);
	while (swap->b.len > 0)
	{
		tg = calculate_costs(swap);
		prepare_rotate(swap, tg);
		pa(swap, 1);
	}
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
