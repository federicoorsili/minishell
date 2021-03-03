/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstprinter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forsili <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 22:42:11 by forsili           #+#    #+#             */
/*   Updated: 2021/03/03 23:23:49 by forsili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		printerscmd(t_scmd *lst)
{
	t_scmd *lstiter;
	int		i;

	i = 0;
	printf("[ ");
	if (lst != NULL)
	{
		lstiter = lst;
		while (lstiter != NULL)
		{
			if (lstiter->next)
				printf("%s->", lstiter->cmd);
			else
				printf("%s", lstiter->cmd);
			lstiter = lstiter->next;
			i++;
		}
	}
	printf(" ]");
}

void		printercmds(t_cmds *lst)
{
	t_cmds *lstiter;
	int		i;

	if (lst != NULL)
	{
		lstiter = lst;
		while (lstiter != NULL)
		{
			i = 0;
			while (lstiter->comand[i])
			{
				printerscmd(lstiter->comand[i]);
				i++;
			}
			printf("\n");
			if (lstiter->prev)
				lstiter = lstiter->prev;
			else
				return ;
		}
	}
}