/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_number_repeated.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 11:03:18 by atahiri-          #+#    #+#             */
/*   Updated: 2025/12/01 11:16:17 by atahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_number_repeated(t_circular_stack *stack)
{
	int		num;
	long	i;

	if (stack->len <= 0)
		return (0);
	num = *stack_get(stack, 0);
	i = 1;
	while (i < stack->len)
	{
		if (num == *stack_get(stack, i))
			return (1);
		i++;
	}
	return (0);
}
