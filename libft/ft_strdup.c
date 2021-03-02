/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduregon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 10:55:56 by aduregon          #+#    #+#             */
/*   Updated: 2021/01/12 10:55:58 by aduregon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	size;
	char	*dup;

	size = ft_strlen(s1);
	if (!(dup = ft_calloc(size + 1, sizeof(char))))
		return (NULL);
	ft_memcpy(dup, s1, size);
	dup[size] = '\0';
	return (dup);
}
