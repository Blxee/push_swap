/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 11:34:31 by atahiri-          #+#    #+#             */
/*   Updated: 2025/12/02 12:48:00 by atahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	apply_oprations(t_swap_stack *swap)
{
	static t_operation	arr[][127][127] = {
	['s'] = {['a'] = {['\n'] = sa}, ['b'] = {['\n'] = sb},
	['s'] = {['\n'] = ss}},
	['p'] = {['a'] = {['\n'] = pa}, ['b'] = {['\n'] = pb}},
	['r'] = {['a'] = {['\n'] = ra}, ['b'] = {['\n'] = rb},
	['r'] = {['a'] = rra, ['b'] = rrb, ['r'] = rrr}}};
	char				buf[4];
	t_operation			op;

	while (1)
	{
		op = NULL;
		if (read(0, buf, 3) < 3)
			return (0);
		if (buf[2] != '\n' && ((read(0, buf + 3, 1) == 1) * buf[3]) != '\n')
			return (1);
		op = arr[(size_t)buf[0]][(size_t)buf[1]][(size_t)buf[2]];
		if (!op)
			return (1);
		op(swap, 1);
	}
	return (0);
}

#include <stdio.h>
void	print_stack(t_circular_stack *stack)
{
	printf("\nstack\n");
	for (long i = 0; i < stack->len; i++)
		printf("%d\n", *stack_get(stack, i));
}

int	main(int argc, char **argv)
{
	t_swap_stack			*swap;

	if (argc <= 1)
		return (0);
	swap = swap_stack_new(count_args(argc, argv));
	if (!swap)
		return (0);
	parse_args(swap, argc, argv);
	if (apply_oprations(swap))
		return (ft_putstr_fd(2, "Error\n"), swap_stack_free(&swap), 255);
	print_stack(&swap->a);
	print_stack(&swap->b);
	if (stack_sorted(&swap->a) && swap->b.len == 0)
		ft_putstr_fd(1, "OK\n");
	else
		ft_putstr_fd(1, "KO\n");
	swap_stack_free(&swap);
	return (0);
}
