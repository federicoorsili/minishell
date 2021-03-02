/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduregon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 11:05:51 by aduregon          #+#    #+#             */
/*   Updated: 2021/01/12 11:05:52 by aduregon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list *lstiter;

	if (lst != NULL)
	{
		lstiter = lst;
		while (lstiter != NULL)
		{
			(*f)(lstiter->content);
			lstiter = lstiter->next;
		}
	}
}
