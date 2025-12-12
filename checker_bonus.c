/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 11:34:31 by atahiri-          #+#    #+#             */
/*   Updated: 2025/12/12 08:09:35 by atahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <malloc.h>

static t_operation	*parse_operations(void)
{
	static t_operation	arr[][127][127] = {
	['s'] = {['a'] = {['\n'] = sa}, ['b'] = {['\n'] = sb},
	['s'] = {['\n'] = ss}},
	['p'] = {['a'] = {['\n'] = pa}, ['b'] = {['\n'] = pb}},
	['r'] = {['a'] = {['\n'] = ra}, ['b'] = {['\n'] = rb},
	['r'] = {['\n'] = rr, ['a'] = rra, ['b'] = rrb, ['r'] = rrr}}};
	static t_operation	operations[10000];
	int					i;
	char				*buf;

	i = ~0;
	while (1)
	{
		buf = (char [4]){0};
		operations[++i] = NULL;
		if (read(0, buf, 3) <= 0)
			return (operations);
		if (buf[2] != '\n' && ((read(0, buf + 3, 1) == 1) * buf[3]) != '\n')
			return (NULL);
		operations[i] = arr[(size_t)buf[0]][(size_t)buf[1]][(size_t)buf[2]];
		if (!operations[i])
			return (NULL);
	}
}

int	main(int argc, char **argv)
{
	t_swap_stack			*swap;
	t_operation				*operations;

	if (argc <= 1)
		return (0);
	swap = swap_stack_new(count_args(argc, argv));
	if (!swap)
		return (0);
	parse_args(swap, argc, argv);
	operations = parse_operations();
	if (!operations)
		return (ft_putstr_fd(2, "Error\n"), swap_stack_free(&swap), 255);
	while (*operations)
		(*operations++)(swap, 0);
	if (stack_sorted(&swap->a) && swap->b.len == 0)
		ft_putstr_fd(1, "OK\n");
	else
		ft_putstr_fd(1, "KO\n");
	swap_stack_free(&swap);
	return (0);
}
