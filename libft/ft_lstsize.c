/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduregon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 11:04:22 by aduregon          #+#    #+#             */
/*   Updated: 2021/01/12 11:04:24 by aduregon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_lstsize(t_list *lst)
{
	int		size;
	t_list	*elem;

	size = 0;
	elem = lst;
	while (elem != NULL)
	{
		elem = elem->next;
		size++;
	}
	return (size);
}
