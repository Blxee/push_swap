/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 11:03:01 by atahiri-          #+#    #+#             */
/*   Updated: 2025/12/01 11:03:06 by atahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_swap_stack *swap)
{
	t_circular_stack	*a;
	t_circular_stack	*b;

	ft_putstr("pa\n");
	a = &swap->a;
	b = &swap->b;
	stack_push_back(a, stack_pop(b));
}

void	pb(t_swap_stack *swap)
{
	t_circular_stack	*a;
	t_circular_stack	*b;

	ft_putstr("pb\n");
	a = &swap->a;
	b = &swap->b;
	stack_push_back(b, stack_pop(a));
}
