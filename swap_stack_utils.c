/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_stack_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 11:01:05 by atahiri-          #+#    #+#             */
/*   Updated: 2025/12/10 12:16:36 by atahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_swap_stack	*swap_stack_new(long num_size)
{
	t_swap_stack	*swap;

	swap = malloc(sizeof(t_swap_stack));
	if (!swap)
		return (NULL);
	swap->ranked = NULL;
	swap->a.len = 0;
	swap->a.start = 0;
	swap->a = (t_circular_stack){
		.buf = malloc(sizeof(t_node) * (size_t)num_size),
		.capacity = num_size,
		.len = 0,
		.start = 0,
	};
	if (!swap->a.buf)
		return (free(swap), NULL);
	swap->b = (t_circular_stack){
		.buf = malloc(sizeof(t_node) * (size_t)num_size),
		.capacity = num_size,
		.len = 0,
		.start = 0,
	};
	if (!swap->b.buf)
		return (free(swap->a.buf), free(swap), NULL);
	return (swap);
}

void	swap_stack_free(t_swap_stack **swap)
{
	if (!swap || !*swap)
		return ;
	if ((*swap)->a.buf)
		free((*swap)->a.buf);
	if ((*swap)->b.buf)
		free((*swap)->b.buf);
	if ((*swap)->ranked)
		free((*swap)->ranked);
	free(*swap);
	*swap = NULL;
}
