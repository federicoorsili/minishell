/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstprinter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forsili <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 22:42:11 by forsili           #+#    #+#             */
/*   Updated: 2021/03/02 22:47:50 by forsili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		printerscmd(t_scmd *lst)
{
	t_scmd *lstiter;

	if (lst != NULL)
	{
		lstiter = lst;
		while (lstiter != NULL)
		{
			printf("%s-", lstiter->cmd);
			lstiter = lstiter->next;
		}
	}
	printf("\n");
}

void		printercmds(t_cmds *lst)
{
	t_cmds *lstiter;

	if (lst != NULL)
	{
		lstiter = lst;
		while (lstiter != NULL)
		{
			printerscmd(lstiter->comand);
			if (lstiter->next)
				lstiter = lstiter->next;
			else
				return ;
		}
	}
}