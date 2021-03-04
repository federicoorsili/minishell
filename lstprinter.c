/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstprinter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forsili <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 22:42:11 by forsili           #+#    #+#             */
/*   Updated: 2021/03/04 13:34:07 by forsili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		printerscmd(t_scmd *lst)
{
	t_scmd *lstiter;
	int		i;

	i = 0;
	printf(FRED"[ "NONE);
	if (lst != NULL)
	{
		lstiter = lst;
		while (lstiter != NULL)
		{
			printf(FGREEN"("NONE);
			printf(FYELLOW"%s"NONE, lstiter->cmd);
			printf(FGREEN")"NONE);
			lstiter = lstiter->next;
			i++;
		}
	}
	printf(FRED" ]"NONE);
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