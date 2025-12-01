/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 11:02:36 by atahiri-          #+#    #+#             */
/*   Updated: 2025/12/01 11:02:43 by atahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_swap_stack *swap)
{
	t_circular_stack	*a;

	ft_putstr("ra\n");
	a = &swap->a;
	a->start--;
	if (a->start < 0)
		a->start = a->len - 1;
}

void	rb(t_swap_stack *swap)
{
	t_circular_stack	*b;

	ft_putstr("rb\n");
	b = &swap->b;
	b->start--;
	if (b->start < 0)
		b->start = b->len - 1;
}

void	rr(t_swap_stack *swap)
{
	ra(swap);
	rb(swap);
}
