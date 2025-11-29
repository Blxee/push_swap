/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 17:54:37 by atahiri-          #+#    #+#             */
/*   Updated: 2025/11/29 14:05:23 by atahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_swap_stack	*swap_stack_new(size_t num_size)
{
	t_swap_stack *swap;
	
	swap = malloc(sizeof(t_swap_stack));
	if (!swap)
		return (NULL);

	swap->a.len = 0;
	swap->a.start = 0;

	swap->a = (t_cicular_stack) {
		.buf = malloc(sizeof(int) * num_size),
		.capacity = num_size, .len = 0, .start = 0,
	};
	swap->a.buf = malloc(sizeof(int) * num_size);
	if (!swap->a.buf)
		return (free(swap), NULL);

	swap->b = (t_cicular_stack) {
		.buf = malloc(sizeof(int) * num_size),
		.capacity = num_size, .len = 0, .start = 0,
	};
	swap->b.buf = malloc(sizeof(int) * num_size);
	if (!swap->b.buf)
		return (free(swap->a.buf), free(swap), NULL);
	return (swap);
}

void	swap_stack_free(t_swap_stack *swap)
{
	if (!swap)
		return ;
	if (swap->a.buf)
		free(swap->a.buf);
	if (swap->b.buf)
		free(swap->b.buf);
	free(swap);
}

int   *stack_get(t_cicular_stack *stack, size_t idx)
{
	size_t	len;
	int		offset;

	len = stack->len;
	offset = stack->start;
	idx = (idx + offset) % len;
	return (&stack->buf[idx]);
}

void  stack_push(t_cicular_stack *stack, int val)
{
	size_t i;

	i = stack->len;
	while (i > stack->start)
	{
		stack->buf[i] = stack->buf[i - 1];
		i--;
	}
	*stack_get(a, a->len++) = *stack_get(b, b->len--);
}

int   stack_pop(t_cicular_stack *stack);

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

void	ft_putstr(const char *str)
{
	int len;

	len = 0;
	while (str && str[len])
		len++;
	write(1, str, len);
}

void	apply_op(t_swap_stack *swap, t_operation op)
{
	static const t_operation keys[] = { sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr, };
	static const char *vals[] = {
		"sa\n",	 "sb\n",  "sa\nsb\n",
		"pa\n",  "pb\n",
		"ra\n",  "rb\n",  "ra\nrb\n",
		"rra\n", "rrb\n", "rra\nrrb\n",
	};
	int i;

	if (op && swap)
	{
		op(swap);
		i = 0;
		while (i < (int)(sizeof(keys) / sizeof(*keys)))
		{
			if (keys[i] == op)
			{
				ft_putstr(vals[i]);
			}
			i++;
		}
	}
}

void	sa(t_swap_stack *swap)
{
	t_cicular_stack *stack;
	int tmp;

	stack = &swap->a;
	if (stack->len < 2)
		return ;
	tmp = *stack_get(stack, -1);
	*stack_get(stack, -1) = *stack_get(stack, -2);
	*stack_get(stack, -2)  = tmp;
}

void	sb(t_swap_stack *swap)
{
	t_cicular_stack *stack;
	int tmp;

	stack = &swap->b;
	if (stack->len < 2)
		return ;
	tmp = *stack_get(stack, -1);
	*stack_get(stack, -1) = *stack_get(stack, -2);
	*stack_get(stack, -2) = tmp;
}

void	ss(t_swap_stack *swap)
{
	sa(swap);
	sb(swap);
}

void	pa(t_swap_stack *swap)
{
	t_cicular_stack *a;
	t_cicular_stack *b;
	size_t i;

	a = &swap->a;
	b = &swap->b;
	i = a->len;
	while (i > a->start)
	{
		a->buf[i] = a->buf[i - 1];
		i--;
	}
	*stack_get(a, a->len++) = *stack_get(b, b->len--);
}

void	pb(t_swap_stack *swap)
{
	(void)swap;
}

void	ra(t_swap_stack *swap)
{
	t_cicular_stack *a;

	a = &swap->a;
	a->start++;
}

void	rb(t_swap_stack *swap)
{
	t_cicular_stack *b;

	b = &swap->b;
	b->start++;
}

void	rr(t_swap_stack *swap)
{
	ra(swap);
	rb(swap);
}

void	rra(t_swap_stack *swap)
{
	t_cicular_stack *a;

	a = &swap->a;
	a->start--;
}

void	rrb(t_swap_stack *swap)
{
	t_cicular_stack *b;

	b = &swap->b;
	b->start--;
}

void	rrr(t_swap_stack *swap)
{
	rra(swap);
	rrb(swap);
}

#include <stdio.h>
void print_stack(t_cicular_stack *stack)
{
	printf("\nstack\n");
	for (size_t i = 0; i < stack->len; i++)
		printf("%d\n", *stack_get(stack, i));
}

int	main(int argc, char **argv)
{
	t_swap_stack *swap;
	int nbr;
	int fail;

	swap = swap_stack_new(100);
	if (!swap)
		return (0);
	fail = 0;
	while (--argc > 0)
	{
		nbr = ft_atoi(*(++argv), &fail);
		if (fail)
			return (swap_stack_free(swap), 0);
		// swap->a.buf[swap->a.len++] = nbr;
		swap->b.buf[swap->b.len++] = nbr;
	}
	print_stack(&swap->a);
	print_stack(&swap->b);
	pa(swap);
	print_stack(&swap->a);
	print_stack(&swap->b);
	swap_stack_free(swap);
	return (0);
}
