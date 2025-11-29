/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 17:54:37 by atahiri-          #+#    #+#             */
/*   Updated: 2025/11/29 11:24:36 by atahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_swap_stack	*swap_stack_new(int num_size)
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
	static const char *vals[] = { "sa", "sb", "ss", "pa", "pb", "ra", "rb", "rr", "rra", "rrb", "rrr", };
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
				write(1, "\n", 1);
			}
			i++;
		}
	}
}

void	sa(t_swap_stack *swap) {(void)swap;}
void	sb(t_swap_stack *swap) {(void)swap;}
void	ss(t_swap_stack *swap) {(void)swap;}
void	pa(t_swap_stack *swap) {(void)swap;}
void	pb(t_swap_stack *swap) {(void)swap;}
void	ra(t_swap_stack *swap) {(void)swap;}
void	rb(t_swap_stack *swap) {(void)swap;}
void	rr(t_swap_stack *swap) {(void)swap;}
void	rra(t_swap_stack *swap) {(void)swap;}
void	rrb(t_swap_stack *swap) {(void)swap;}
void	rrr(t_swap_stack *swap) {(void)swap;}

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
		swap->a.buf[swap->a.len++] = nbr;
	}
	apply_op(swap, sb);
	apply_op(swap, sa);
	swap_stack_free(swap);
	return (0);
}
