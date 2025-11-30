/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 14:52:36 by atahiri-          #+#    #+#             */
/*   Updated: 2025/11/30 16:59:44 by atahiri-         ###   ########.fr       */
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

int	ft_atoi(const char *nptr, int *fail)
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
	while (nptr[i] && !ft_isspace(nptr[i]))
	{
		if (!ft_isdigit(nptr[i]))
			return (fail = 0, 0);
		nbr = nbr * 10 + nptr[i] - '0';
		if ((sign == 1 && nbr > INT_MAX)
			|| (sign == -1 && nbr > -(long)INT_MIN))
			return (*fail = 1, 0);
		i++;
	}
	return (sign * nbr);
}
