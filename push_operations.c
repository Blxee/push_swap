/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 11:03:01 by atahiri-          #+#    #+#             */
/*   Updated: 2025/12/02 11:42:47 by atahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_swap_stack *swap, int show)
{
	t_circular_stack	*a;
	t_circular_stack	*b;

	if (!swap || !swap->a.buf || !swap->b.buf)
		return ;
	if (show)
		ft_putstr_fd(1, "pa\n");
	a = &swap->a;
	b = &swap->b;
	if (b->len > 0)
		stack_push_back(a, stack_pop(b));
}

void	pb(t_swap_stack *swap, int show)
{
	t_circular_stack	*a;
	t_circular_stack	*b;

	if (!swap || !swap->a.buf || !swap->b.buf)
		return ;
	if (show)
		ft_putstr_fd(1, "pb\n");
	a = &swap->a;
	b = &swap->b;
	if (a->len > 0)
		stack_push_back(b, stack_pop(a));
}
