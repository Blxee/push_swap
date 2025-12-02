/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 17:54:37 by atahiri-          #+#    #+#             */
/*   Updated: 2025/12/02 17:30:46 by atahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>
void	print_stack(t_circular_stack *stack)
{
	printf("\nstack\n");
	for (long i = 0; i < stack->len; i++)
		printf("%d\n", *stack_get(stack, i));
}

void	sort_3(t_swap_stack *swap)
{
	int	min;
	int	max;
	int	min_idx;
	int	max_idx;
	int	i;

	min = INT_MAX;
	max = INT_MIN;
	i = -1;
	while (++i < 3)
	{
		if (*stack_get(&swap->a, i) <= min)
		{
			min_idx = i;
			min = *stack_get(&swap->a, i);
		}
		if (*stack_get(&swap->a, i) >= max)
		{
			max_idx = i;
			max = *stack_get(&swap->a, i);
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
