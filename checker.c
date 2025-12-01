/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 11:34:31 by atahiri-          #+#    #+#             */
/*   Updated: 2025/12/01 14:54:22 by atahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_strncmp(const char *s1, const char *s2, int n)
{
	int	i;

	if (!s1 || !s2)
		return (0);
	i = 0;
	while (i < n && s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	if (i < n)
		return (s1[i] - s2[i]);
	return (0);
}

static int	apply_oprations(void)
{
	static char				*keys[] = {
		"sa", "sb", "ss", "pa", "pb", "ra", "rb", "rr", "rra", "rrb", "rrr",
	};
	static t_operation		vals[] = {
		sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr,
	};
	char					buf[3];
	int						len;

	(void)keys;
	(void)vals;
	len = 0;
	while (1)
	{
		if (read(0, buf + len++, 1) <= 0)
			break ;
		if (len == 3)
			;
	}
	return (1);
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
	if (apply_oprations())
		return (swap_stack_free(&swap), 255);
	if (stack_sorted(&swap->a) && swap->b.len == 0)
		ft_putstr_fd(1, "OK\n");
	else
		ft_putstr_fd(1, "KO\n");
	swap_stack_free(&swap);
	return (0);
}
