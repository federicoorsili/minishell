/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forsili <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 22:14:44 by forsili           #+#    #+#             */
/*   Updated: 2021/03/04 13:31:19 by forsili          ###   ########.fr       */
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

t_scmd	*close_scmd_lst(t_scmd **start, t_scmd *last)
{
	t_scmd *tmp;

	tmp = newsimplecmd(0, last);
	add_back_smplcmds(start, tmp);
	return (tmp);
}

t_cmds	*create_cmds_lst(t_cmds **start, t_cmds *last, t_scmd **comands)
{
	t_cmds *tmp;

	tmp = newcomands(comands, last);
	add_back_cmds(start, tmp);
	return (tmp);
}

t_cmds		*iterator2(t_cmds *lst)
{
	t_cmds *lstiter;

	if (lst != NULL)
	{
		lstiter = lst;
		while (lstiter != NULL)
		{
			if (lstiter->next)
				lstiter = lstiter->next;
			else
				return (lstiter);
		}
	}
	return (0);
}

t_cmds		*parse_cmd(char **cmd, t_cmds *cmdslst)
{
	char	**arr;
	char	**cmdarr;
	t_cmds	*tmplast;
	t_scmd	**comand;
	t_scmd	*tmp;
	int		i;
	int		k;

	*cmd = ft_strtrim(*cmd, "\n");
	*cmd = ft_strtrim(*cmd, " ");
	cmdarr = ft_splitter(*cmd, ';');
	i = 0;
	while (cmdarr[i])
	{
		cmdarr[i] = ft_strtrim(cmdarr[i], " ");
		i++;
	}
	if (!(comand = malloc((i + 1) * sizeof(t_scmd *))))
		return (0);
	k = 0;
	while (cmdarr[k])
	{
		arr = ft_split_cmd(cmdarr[k], "<>|");
		comand[k] = newsimplecmd(arr[0], 0);
		i = 1;
		while (arr[i])
		{
			tmp = create_scmd_lst(&comand[k], tmp, i, arr);
			i++;
		}
		free(arr);
		k++;
	}
	comand[k] = 0;
	tmplast = create_cmds_lst(&cmdslst, iterator2(cmdslst), comand);
	free(cmdarr);
	return (tmplast);
}
