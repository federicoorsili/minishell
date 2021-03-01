/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forsili <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 22:14:44 by forsili           #+#    #+#             */
/*   Updated: 2021/03/02 00:40:12 by forsili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_scmd	*create_scmd_lst(t_scmd **start, t_scmd *last, int i, char **arr)
{
	t_scmd *tmp;

	tmp = newsimplecmd(arr[i], last);
	add_back_smplcmds(start, tmp);
	return (tmp);
}

void		iterator(t_scmd *lst)
{
	t_scmd *lstiter;

	if (lst != NULL)
	{
		lstiter = lst;
		while (lstiter != NULL)
		{
			printf("%s-",lstiter->cmd);
			lstiter = lstiter->next;
		}
	}
	printf("\n");
}

t_cmds		*parse_cmd(char **cmd, t_cmds *last)
{
	char	**arr;
	char	**cmdarr;
	t_cmds	*newlast;
	t_scmd	*comand;
	t_scmd	*tmp;
	int		i;
	int		k;

	*cmd = ft_strtrim(*cmd, "\n");
	*cmd = ft_strtrim(*cmd, " ");
	cmdarr = ft_split(*cmd, ';');
	k = -1;
	while (cmdarr[++k])
	{
		arr = ft_split_cmd(cmdarr[k], ' ');
		comand = newsimplecmd(arr[0], 0);
		last = newcomands(comand, last);
		tmp = comand;
		i = 1;
		while (arr[i])
			tmp = create_scmd_lst(&comand, tmp, i++, arr);
		newlast = newcomands(comand, last);
		add_back_cmds(&last, newlast);
		free(last);
		last = newlast;
		iterator(comand);
	}
	return (newlast);
}