/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 17:54:37 by atahiri-          #+#    #+#             */
/*   Updated: 2025/11/18 17:57:24 by atahiri-         ###   ########.fr       */
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
			return (free(stacks), 0);
		stack_add_front(&stacks->a, nbr);
	}
	free(stacks);
	return (0);
}
