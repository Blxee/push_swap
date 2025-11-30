/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 14:52:36 by atahiri-          #+#    #+#             */
/*   Updated: 2025/11/30 14:05:22 by atahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

static void	ft_setsign(int *sign, size_t *i, const char *nptr)
{
	*sign = 1;
	if (nptr[*i] == '+' || nptr[*i] == '-')
	{
		if (nptr[*i] == '-')
			*sign = -1;
		(*i)++;
	}
}

int	ft_atoi(const char *nptr)
{
	size_t	i;
	long	nbr;
	int		sign;

	if (nptr == NULL)
		return (0);
	nbr = 0;
	i = 0;
	while (ft_isspace(nptr[i]))
		i++;
	ft_setsign(&sign, &i, nptr);
	while (ft_isdigit(nptr[i]))
	{
		nbr = nbr * 10 + nptr[i] - '0';
		if (nbr < 0)
		{
			if (sign > 0)
				return (-1);
			else
				return (0);
		}
		i++;
	}
	return (sign * nbr);
}
