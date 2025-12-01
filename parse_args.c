/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 11:03:10 by atahiri-          #+#    #+#             */
/*   Updated: 2025/12/01 11:03:15 by atahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	parse_args(t_swap_stack *swap, int argc, char **argv)
{
	char	**splt;
	int		i;
	int		fail;

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
		if (i == 0 || fail || is_number_repeated(&swap->a))
		{
			ft_putstr("Error\n");
			swap_stack_free(&swap);
			exit(255);
		}
	}
}
