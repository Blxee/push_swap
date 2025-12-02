/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 17:54:37 by atahiri-          #+#    #+#             */
/*   Updated: 2025/12/02 18:34:56 by atahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>
void	print_stack(t_circular_stack *stack)
{
	printf("\nstack\n");
	for (long i = 0; i < stack->len; i++)
		printf("%d\n", stack_get(stack, i)->val);
}

void	sort_3(t_swap_stack *swap)
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

int	main(int argc, char **argv)
{
	t_swap_stack	*swap;

	if (argc <= 1)
		return (0);
	swap = swap_stack_new(count_args(argc, argv));
	if (!swap)
		return (0);
	parse_args(swap, argc, argv);
	sort_3(swap);
	print_stack(&swap->a);
	print_stack(&swap->b);
	swap_stack_free(&swap);
	return (0);
}
