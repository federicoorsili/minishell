/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduregon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 11:02:27 by aduregon          #+#    #+#             */
/*   Updated: 2021/01/12 11:02:30 by aduregon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	unsigned char *str;

	if (!s)
		return ;
	str = (unsigned char *)s;
	while (*str)
	{
		ft_putchar_fd(*str++, fd);
	}
}
