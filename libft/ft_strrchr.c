/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduregon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 10:58:28 by aduregon          #+#    #+#             */
/*   Updated: 2021/01/12 10:58:30 by aduregon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t index;

	index = ft_strlen(s);
	while (1)
	{
		if (((unsigned char *)s)[index] == (unsigned char)c)
			return ((char *)s + index);
		if (index == 0)
			break ;
		index--;
	}
	return (NULL);
}
