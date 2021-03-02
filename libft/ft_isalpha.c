/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduregon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 10:52:03 by aduregon          #+#    #+#             */
/*   Updated: 2021/01/12 10:52:05 by aduregon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isalpha(int c)
{
	return (((unsigned char)c >= 'A' && (unsigned char)c <= 'Z') ||
			((unsigned char)c >= 'a' && (unsigned char)c <= 'z'));
}
