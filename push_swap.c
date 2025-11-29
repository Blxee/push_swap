/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 17:54:37 by atahiri-          #+#    #+#             */
/*   Updated: 2025/11/28 20:41:18 by blxee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_swap_stack *swap_stack_new(void)
{
	t_swap_stack *stacks;
	
	stacks = malloc(sizeof(t_swap_stack));
	if (!stacks)
		return (NULL);
	stacks->a = NULL;
	stacks->b = NULL;
	return (stacks);
}

void	stack_add_back(t_stack **stack, int val)
{
	t_stack *prev;
	t_stack **curr;

	prev = NULL;
	curr = stack;
	while (*curr)
	{
		prev = *curr;
		curr = &(*curr)->next;
	}
	*curr = malloc(sizeof(t_stack));
	if (*curr)
	{
		(*curr)->val = val;
		(*curr)->next = NULL;
		(*curr)->prev = NULL;
	}
	(void)prev;
	/* if (prev) */
	/* 	; */
}

void	stack_add_front(t_stack **stack, int val)
{
	t_stack *new;

	new = malloc(sizeof(t_stack));
	if (new)
	{
		new->val = val;
		new->prev = NULL;
		if (*stack)
			new->prev = (*stack)->prev;
		new->next = *stack;
		*stack = new;
	}
}

void	stack_delete(t_stack **stack)
{
	t_stack **next;

	while (*stack)
	{
		next = &(*stack)->next;
		stack = &(*stack)->next;
		free(*stack);
		*stack = NULL;
		stack = next;
	}
}

void	swap_stack_free(t_swap_stack *stacks)
{
	if (!stacks)
		return ;
	if (stacks->a)
		stack_delete(&stacks->a);
	if (stacks->b)
		stack_delete(&stacks->b);
	free(stacks);
}

int	ft_atoi(char *str, int *fail)
{
  int prev;
  int nbr;
  int sign;

  prev = 0;
  nbr = 0;
  sign = 1;
  if (*str == '-')
    sign = -1;
  while (*str)
  {
    if (*str < '0' || *str > '9')
      *fail = 1;
    nbr = nbr * 10 + *str - '0';
    if (nbr < prev)
      *fail = 1;
    prev = nbr;
    str++;
  }
  return (sign * nbr);
}

int	main(int argc, char **argv)
{
	t_swap_stack *stacks;
	int nbr;
	int fail;

	stacks = swap_stack_new();
	if (!stacks)
		return (0);
	fail = 0;
	while (--argc > 0)
	{
		nbr = ft_atoi(*(++argv), &fail);
		if (fail)
			return (swap_stack_free(stacks), 0);
		stack_add_front(&stacks->a, nbr);
	}
	free(stacks);
	return (0);
}
