/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 20:48:35 by atahiri-          #+#    #+#             */
/*   Updated: 2025/11/30 13:53:07 by atahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	**ft_alloc_strs(char const *s)
{
	size_t	i;
	size_t	len;
	size_t	count;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] != '\0' && ft_isspace(s[i]))
			i++;
		len = 0;
		while (s[i + len] != '\0' && !ft_isspace(s[i + len]))
			len++;
		if (len > 0)
		{
			count++;
			i += len;
		}
		else if (s[i] != '\0')
			i++;
	}
	return (malloc((count + 1) * sizeof(char *)));
}

static size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;

	if (dst == NULL || src == NULL)
		return (0);
	src_len = 0;
	while (src[src_len])
		src_len++;
	if (size > 0)
	{
		i = 0;
		while (i < size - 1 && src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (src_len);
}

size_t	ft_make_str(char ***arr, size_t *arr_idx, size_t len, const char *s)
{
	if (len == 0)
		return (0);
	(*arr)[*arr_idx] = malloc(len + 1);
	if ((*arr)[*arr_idx] == NULL)
	{
		while (*arr_idx > 0)
			free((*arr)[--*arr_idx]);
		free(*arr);
		*arr = NULL;
		return (0);
	}
	ft_strlcpy((*arr)[*arr_idx], s, len + 1);
	(*arr_idx)++;
	return (len);
}

char	**ft_split(char const *s)
{
	char	**arr;
	size_t	arr_idx;
	size_t	i;
	size_t	len;

	if (s == NULL)
		return (NULL);
	arr = ft_alloc_strs(s);
	arr_idx = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (arr == NULL)
			return (NULL);
		while (s[i] != '\0' && ft_isspace(s[i]))
			i++;
		len = 0;
		while (s[i + len] != '\0' && !ft_isspace(s[i + len]))
			len++;
		i += ft_make_str(&arr, &arr_idx, len, s + i);
		if (len == 0 && s[i] != '\0')
			i++;
	}
	arr[arr_idx] = NULL;
	return (arr);
}
