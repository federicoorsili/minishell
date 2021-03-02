/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduregon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 11:04:41 by aduregon          #+#    #+#             */
/*   Updated: 2021/01/12 11:04:43 by aduregon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstlast(t_list *lst)
{
	t_list *elem;

	elem = lst;
	if (elem != NULL)
	{
		while (elem != NULL)
		{
			if (elem->next == NULL)
				return (elem);
			elem = elem->next;
		}
	}
	return (NULL);
}
