/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduregon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 11:05:01 by aduregon          #+#    #+#             */
/*   Updated: 2021/01/12 11:05:04 by aduregon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list *lastelem;

	if (*alst == NULL)
	{
		*alst = new;
	}
	else
	{
		lastelem = ft_lstlast(*alst);
		if (lastelem != NULL)
			lastelem->next = new;
	}
}
