/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduregon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 10:50:36 by aduregon          #+#    #+#             */
/*   Updated: 2021/01/12 10:50:50 by aduregon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	size_t				index;
	int					neg;
	unsigned long int	res;

	index = 0;
	neg = 1;
	res = 0;
	while (ft_isspace(str[index]))
		index++;
	if (str[index] == '+' || str[index] == '-')
	{
		if (str[index] == '-')
			neg = -1;
		index++;
	}
	while (ft_isdigit(str[index]))
	{
		res *= 10;
		res += str[index] - 48;
		index++;
	}
	return (res * neg);
}
