/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduregon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 11:01:42 by aduregon          #+#    #+#             */
/*   Updated: 2021/01/12 11:01:45 by aduregon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*strmapi;
	size_t	size;
	size_t	index;

	size = ft_strlen(s);
	if (!(strmapi = ft_calloc(size + 1, sizeof(char))))
		return (NULL);
	index = 0;
	while (index < size)
	{
		strmapi[index] = (*f)(index, s[index]);
		index++;
	}
	strmapi[index] = '\0';
	return (strmapi);
}
