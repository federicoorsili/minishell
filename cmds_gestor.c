/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds_gestor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forsili <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 23:02:47 by forsili           #+#    #+#             */
/*   Updated: 2021/03/03 22:25:09 by forsili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmds		*newcomands(t_scmd **cmd, t_cmds *previous)
{
	t_cmds *element;

	if (!(element = malloc(sizeof(t_cmds))))
		return (NULL);
	element->comand = cmd;
	element->next = NULL;
	element->prev = previous;
	return (element);
}

t_cmds		*lstlast_cmds(t_cmds *lst)
{
	t_cmds *elem;

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

void		add_back_cmds(t_cmds **alst, t_cmds *new)
{
	t_cmds *lastelem;

	if (*alst == NULL)
	{
		*alst = new;
	}
	else
	{
		lastelem = lstlast_cmds(*alst);
		if (lastelem != NULL)
			lastelem->next = new;
	}
}

void		lstclear_cmds(t_cmds **lst, void (*del)(void *))
{
	t_cmds *tmp;

	while (*lst != NULL)
	{
		tmp = (*lst)->next;
		(*del)((*lst)->comand);
		free(*lst);
		*lst = tmp;
	}
}
