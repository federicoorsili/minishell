/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forsili <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 22:32:21 by forsili           #+#    #+#             */
/*   Updated: 2021/03/01 22:32:42 by forsili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			is_line(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

size_t		ft_strlen(const char *s)
{
	size_t size;

	if (!s)
		return (0);
	size = 0;
	while (s[size] != 0)
		size++;
	return (size);
}

void		*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t index;

	index = 0;
	while (src && index < n)
	{
		((unsigned char *)dst)[index] = ((unsigned char *)src)[index];
		index++;
	}
	return (dst);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*strjoin;
	size_t	dim_s1;
	size_t	dim_s2;
	size_t	tot_len;

	if (!s1 && !s2)
		return (0);
	dim_s1 = ft_strlen((char *)s1);
	dim_s2 = ft_strlen((char *)s2);
	tot_len = dim_s1 + dim_s2 + 1;
	if (!(strjoin = malloc(tot_len * sizeof(char))))
		return (NULL);
	ft_memcpy(strjoin, s1, dim_s1);
	ft_memcpy(strjoin + dim_s1, s2, dim_s2);
	strjoin[tot_len - 1] = '\0';
	free((char *)s1);
	return (strjoin);
}