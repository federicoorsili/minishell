/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scmd_gestor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forsili <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 23:05:51 by forsili           #+#    #+#             */
/*   Updated: 2021/03/04 17:28:50 by forsili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_scmd		*newsimplecmd(char *cmd, t_scmd *previous)
{
	t_scmd *element;

	if (!(element = malloc(sizeof(t_scmd))))
		return (NULL);
	element->cmd = cmd;
	element->next = NULL;
	element->prev = previous;
	return (element);
}

t_scmd		*lstlast_smplcmds(t_scmd *lst)
{
	t_scmd *elem;

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

int		lstcounter_smplcmds(t_scmd *lst)
{
	t_scmd	*elem;
	int		i;

	i = 0;
	elem = lst;
	if (elem != NULL)
	{
		while (elem != NULL)
		{
			if (elem->next == NULL)
			{
				i++;
				return (i);
			}
			elem = elem->next;
			i++;
		}
	}
	return (i);
}

void		add_back_smplcmds(t_scmd **alst, t_scmd *new)
{
	t_scmd *lastelem;

	if (*alst == NULL)
	{
		*alst = new;
	}
	else
	{
		lastelem = lstlast_smplcmds(*alst);
		if (lastelem != NULL)
			lastelem->next = new;
	}
}

void		lstclear_smplcmds(t_scmd **lst, void (*del)(void *))
{
	t_scmd *tmp;

	while (*lst != NULL)
	{
		tmp = (*lst)->next;
		(*del)((*lst)->cmd);
		free(*lst);
		*lst = tmp;
	}
}
