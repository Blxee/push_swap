/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 10:59:24 by atahiri-          #+#    #+#             */
/*   Updated: 2025/12/01 11:00:47 by atahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	count_args(int argc, char **argv)
{
	long	count;
	long	i;
	long	j;
	char	*str;

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
			count += (j > 0);
			if (j == 0 && str[i])
				i++;
		}
		i++;
	}
	return (count);
}
