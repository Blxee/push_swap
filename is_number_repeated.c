/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_number_repeated.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 11:03:18 by atahiri-          #+#    #+#             */
/*   Updated: 2025/12/02 18:35:23 by atahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	is_number_repeated(t_swap_stack *swap)
{
	t_circular_stack	*stack;
	long				i;
	long				j;

	stack = &swap->a;
	if (stack->len <= 0)
		return ;
	i = 0;
	while (i < stack->len)
	{
		j = i + 1;
		while (j < stack->len)
		{
			if (stack_get(stack, i)->val == stack_get(stack, j)->val)
				return (ft_putstr_fd(2, "Error\n"),
					swap_stack_free(&swap), exit(255));
			j++;
		}
		i++;
	}
}
