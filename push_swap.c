/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 17:54:37 by atahiri-          #+#    #+#             */
/*   Updated: 2025/12/06 12:07:58 by atahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>
void	print_stack(t_circular_stack *stack)
{
	printf("\nstack: %ld, start: %ld, cap: %ld\n", stack->len, stack->start, stack->capacity);
	for (long i = 0; i < stack->len; i++)
		printf("%4d=> r: %4d, b: %4d, a: %4d\n", stack_get(stack, i)->val, stack_get(stack, i)->rank, stack_get(stack, i)->cost_b, stack_get(stack, i)->cost_a);
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
	apply_turk(swap);
	// print_stack(&swap->a);
	swap_stack_free(&swap);
	return (0);
}
