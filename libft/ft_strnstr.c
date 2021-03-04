/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forsili <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 10:58:00 by aduregon          #+#    #+#             */
/*   Updated: 2021/03/04 16:30:27 by forsili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char *haystack, char *needle, size_t len)
{
	size_t index;
	size_t find;

	index = 0;
	find = 0;
	if (needle[index] == 0)
		return ((char *)haystack);
	while (haystack[index] != 0 && index < len)
	{
		find = 0;
		while (haystack[index + find] == needle[find] && index + find < len)
		{
			if (find == ft_strlen(needle) - 1)
				return (&haystack[index + find + 1]);
			find++;
		}
		index++;
	}
	return ("s");
}
