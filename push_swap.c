/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 17:54:37 by atahiri-          #+#    #+#             */
/*   Updated: 2025/12/01 09:11:13 by atahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_swap_stack	*swap_stack_new(long num_size)
{
	t_swap_stack *swap;
	
	swap = malloc(sizeof(t_swap_stack));
	if (!swap)
		return (NULL);

	swap->a.len = 0;
	swap->a.start = 0;

	swap->a = (t_circular_stack) {
		.buf = malloc(sizeof(int) * (size_t)num_size),
		.capacity = num_size, .len = 0, .start = 0,
	};
	if (!swap->a.buf)
		return (free(swap), NULL);

	swap->b = (t_circular_stack) {
		.buf = malloc(sizeof(int) * (size_t)num_size),
		.capacity = num_size, .len = 0, .start = 0,
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
	free(*swap);
	*swap = NULL;
}

int   *stack_get(t_circular_stack *stack, long idx)
{
	long	len;
	long	offset;

	len = stack->len;
	offset = stack->start;
	idx += offset;
	while (idx < 0)
		idx += len;
	idx %= len;
	return (&stack->buf[idx]);
}

void  stack_push_back(t_circular_stack *stack, int val)
{
	long i;

	if (!stack)
		return ;
	i = stack->len;
	while (i > stack->start)
	{
		stack->buf[i] = stack->buf[i - 1];
		i--;
	}
	(stack->len)++;
	stack->buf[stack->start++] = val;
}

void					stack_push_front(t_circular_stack *stack, int val)
{
	long i;

	if (!stack)
		return ;
	i = stack->len;
	while (i > stack->start)
	{
		stack->buf[i] = stack->buf[i - 1];
		i--;
	}
	(stack->len)++;
	stack->buf[stack->start] = val;
}

int   stack_pop(t_circular_stack *stack)
{
	long i;
	int val;

	if (!stack || stack->len == 0)
		return (0);
	val = *stack_get(stack, -1);
	i = 0;
	while (i < stack->len - stack->start)
	{
		if (stack->start == 0 && i == 0)
			stack->buf[stack->len - 1] = stack->buf[0];
		else
			stack->buf[stack->start + i - 1] = stack->buf[stack->start + i];
		i++;
	}
	(stack->len)--;
	(stack->start)--;
	if (stack->start < 0)
		stack->start = stack->len - 1;
	return (val);
}

void	ft_putstr(const char *str)
{
	int len;

	len = 0;
	while (str && str[len])
		len++;
	write(1, str, len);
}

void	sa(t_swap_stack *swap)
{
	t_circular_stack *stack;
	int tmp;

	ft_putstr("sa\n");
	stack = &swap->a;
	if (stack->len < 2)
		return ;
	tmp = *stack_get(stack, -1);
	*stack_get(stack, -1) = *stack_get(stack, -2);
	*stack_get(stack, -2)  = tmp;
}

void	sb(t_swap_stack *swap)
{
	t_circular_stack *stack;
	int tmp;

	ft_putstr("sb\n");
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
	t_circular_stack *a;
	t_circular_stack *b;

	ft_putstr("pa\n");
	a = &swap->a;
	b = &swap->b;
	stack_push_back(a, stack_pop(b));
}

void	pb(t_swap_stack *swap)
{
	t_circular_stack *a;
	t_circular_stack *b;

	ft_putstr("pb\n");
	a = &swap->a;
	b = &swap->b;
	stack_push_back(b, stack_pop(a));
}

void	ra(t_swap_stack *swap)
{
	t_circular_stack *a;

	ft_putstr("ra\n");
	a = &swap->a;
	a->start--;
	if (a->start < 0)
		a->start = a->len - 1;
}

void	rb(t_swap_stack *swap)
{
	t_circular_stack *b;

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

void	rra(t_swap_stack *swap)
{
	t_circular_stack *a;

	ft_putstr("rra\n");
	a = &swap->a;
	a->start++;
	if (a->start >= a->len)
		a->start = 0;
}

void	rrb(t_swap_stack *swap)
{
	t_circular_stack *b;

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

#include <stdio.h>
void print_stack(t_circular_stack *stack)
{
	printf("\nstack\n");
	for (long i = 0; i < stack->len; i++)
		printf("%d\n", *stack_get(stack, i));
}

long count_args(int argc, char **argv)
{
	long count;
	long i;
	long j;
	char *str;

	count = 0;
	while (--argc > 0)
	{
		str = *(++argv);
		i = 0;
		while (str[i])
		{
			while (str[i] && ft_isspace(str[i]))
				i++;
			j = 0;
			while (str[i + j] && !ft_isspace(str[i + j]))
				j++;
			i += j;
			if (j)
				count++;
			else if (str[i])
				i++;
		}
		i++;
	}

	return (count);
}

int						is_number_repeated(t_circular_stack *stack)
{
	int		num;
	long	i;

	// WARN: make sure to change this according to the stack fill order
	if (stack->len <= 0)
		return (0);
	num = *stack_get(stack, -1);
	i = 0;
	while (i < stack->len - 1)
	{
		if (num == *stack_get(stack, i))
			return (1);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_swap_stack *swap;
	char **splt;
	int i;
	int fail;

	swap = swap_stack_new(count_args(argc, argv));
	if (argc == 1 || !swap)
		return (0);
	fail = 0;
	while (--argc > 0)
	{
		splt = ft_split(*(++argv));
		i = 0;
		while (splt[i])
			stack_push_front(&swap->a, ft_atoi(splt[i++], &fail));
		i = 0;
		while (splt[i])
			free(splt[i++]);
		free(splt);
		if (fail || is_number_repeated(&swap->a))
			return (ft_putstr("Error\n"), swap_stack_free(&swap), 255);
	}
	print_stack(&swap->a);
	print_stack(&swap->b);
	swap_stack_free(&swap);
	return (0);
}
