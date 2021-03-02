/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduregon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 10:54:53 by aduregon          #+#    #+#             */
/*   Updated: 2021/01/12 10:54:55 by aduregon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*src_temp;
	unsigned char	*dst_temp;
	size_t			index;

	src_temp = (unsigned char *)src;
	dst_temp = (unsigned char *)dst;
	index = 0;
	if (src_temp < dst_temp)
	{
		while (len-- > 0)
			dst_temp[len] = src_temp[len];
	}
	else
	{
		while (index < len)
		{
			dst_temp[index] = src_temp[index];
			index++;
		}
	}
	return (dst);
}
