/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_operations.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 11:02:47 by atahiri-          #+#    #+#             */
/*   Updated: 2025/12/01 11:02:52 by atahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_swap_stack *swap)
{
	t_circular_stack	*a;

	ft_putstr("rra\n");
	a = &swap->a;
	a->start++;
	if (a->start >= a->len)
		a->start = 0;
}

void	rrb(t_swap_stack *swap)
{
	t_circular_stack	*b;

	ft_putstr("rrb\n");
	b = &swap->b;
	b->start++;
	if (b->start >= b->len)
		b->start = 0;
}

void	rrr(t_swap_stack *swap)
{
	rra(swap);
	rrb(swap);
}
