/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_operations.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 11:02:47 by atahiri-          #+#    #+#             */
/*   Updated: 2025/12/01 14:25:59 by atahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_swap_stack *swap, int show)
{
	t_circular_stack	*a;

	if (show)
		ft_putstr_fd(1, "rra\n");
	a = &swap->a;
	a->start++;
	if (a->start >= a->len)
		a->start = 0;
}

void	rrb(t_swap_stack *swap, int show)
{
	t_circular_stack	*b;

	if (show)
		ft_putstr_fd(1, "rrb\n");
	b = &swap->b;
	b->start++;
	if (b->start >= b->len)
		b->start = 0;
}

void	rrr(t_swap_stack *swap, int show)
{
	rra(swap, show);
	rrb(swap, show);
}
