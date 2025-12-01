/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 11:03:32 by atahiri-          #+#    #+#             */
/*   Updated: 2025/12/01 11:38:02 by atahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putstr_fd(const int fd, const char *str)
{
	int	len;

	if (fd < 0 || !str)
		return ;
	len = 0;
	while (str[len])
		len++;
	write(fd, str, len);
}
