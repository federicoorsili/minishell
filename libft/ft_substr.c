/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduregon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 11:00:14 by aduregon          #+#    #+#             */
/*   Updated: 2021/01/12 11:00:16 by aduregon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substr;
	unsigned int	index;

	if (!s)
		return (NULL);
	if (ft_strlen(s) <= start || !len)
		return (ft_strdup(""));
	if (!(substr = ft_calloc(len + 1, sizeof(char))))
		return (NULL);
	index = 0;
	while (len > 0 && s[index + start] != 0)
	{
		((unsigned char *)substr)[index] = ((unsigned char *)s)[start + index];
		index++;
		len--;
	}
	substr[index] = '\0';
	return (substr);
}
