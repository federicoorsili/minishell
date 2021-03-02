/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduregon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 10:53:34 by aduregon          #+#    #+#             */
/*   Updated: 2021/01/12 10:53:36 by aduregon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			index;
	unsigned char	ch;

	index = 0;
	ch = c;
	while (index < n)
	{
		if (((unsigned char *)src)[index] == ch)
		{
			((unsigned char *)dst)[index] = ((unsigned char *)src)[index];
			return (dst + index + 1);
		}
		((unsigned char *)dst)[index] = ((unsigned char *)src)[index];
		index++;
	}
	return (NULL);
}
