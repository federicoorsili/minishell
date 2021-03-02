/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduregon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 10:56:14 by aduregon          #+#    #+#             */
/*   Updated: 2021/01/12 10:56:16 by aduregon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

size_t		ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t index;
	size_t len;

	len = 0;
	index = 0;
	while (dst[len] && len < dstsize)
		len++;
	while ((index + len + 1) < dstsize && src[index])
	{
		((unsigned char *)dst)[index + len] = ((unsigned char *)src)[index];
		index++;
	}
	if (len < dstsize)
		dst[index + len] = '\0';
	return (len + ft_strlen(src));
}
