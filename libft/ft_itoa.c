/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduregon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 11:01:21 by aduregon          #+#    #+#             */
/*   Updated: 2021/01/12 11:01:23 by aduregon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t		ft_nsize(int n)
{
	size_t size;

	size = (n < 0 ? 1 : 0);
	while (1)
	{
		n /= 10;
		size++;
		if (n == 0)
			break ;
	}
	return (size);
}

char				*ft_itoa(int n)
{
	size_t	size;
	char	*itoa;
	long	number;

	number = n;
	size = ft_nsize(n);
	if (!(itoa = ft_calloc(size + 1, sizeof(char))))
		return (NULL);
	if (number < 0)
	{
		itoa[0] = '-';
		number *= -1;
	}
	itoa[size] = '\0';
	while (1)
	{
		itoa[size - 1] = (number % 10) + 48;
		number /= 10;
		size--;
		if (number == 0)
			break ;
	}
	return (itoa);
}
