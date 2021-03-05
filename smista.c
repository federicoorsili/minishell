/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smista.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forsili <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 15:35:27 by forsili           #+#    #+#             */
/*   Updated: 2021/03/05 18:11:48 by forsili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_strnstr_md(char *haystack, char *needle, int len)
{
	size_t index;
	size_t find;

	index = 0;
	find = 0;
	if (needle[index] == 0)
		return (0);
	while (haystack[index] != 0 && index < len)
	{
		find = 0;
		while (haystack[index + find] == needle[find] && index + find < len)
		{
			if (find == ft_strlen(needle) - 1)
				if (haystack[find + 1] == 0)
					return (1);
			find++;
		}
		index++;
	}
	return (0);
}

void	print_env(t_h *h)
{
	int		i;
	char	***tmp;

	tmp = h->env;
	i = 0;
	while (tmp[0][i])
	{
		printf("%s\n", tmp[0][i]);
		i++;
	}
}

char	**src_path(char **tmp)
{
	int		i;
	int		k;
	char	**out;

	i = 0;
	while (tmp[i])
	{
		if (!ft_strncmp(tmp[i], "PATH=", 5))
			break ;
		i++;
	}
	out = ft_split(tmp[i], '=');
	out = ft_split(out[1], ':');
	i = 0;
	while (out[i])
	{
		out[i] = ft_strjoin(out[i], "/");
		printf("%s\n", out[i]);
		i++;
	}
	return (out);
}

char	**sort_list(t_scmd *cmd)
{
	int		i;
	char	**matrix;
	t_scmd	*lstiter;

	i = lstcounter_smplcmds(cmd);
	if (!(matrix = malloc((i + 1) * sizeof(char *))))
		return (0);
	i = 0;
	if (cmd != NULL)
	{
		lstiter = cmd;
		while (lstiter != NULL)
		{
			matrix[i] = lstiter->cmd;
			lstiter = lstiter->next;
			i++;
		}
	}
	matrix[i] = 0;
	return (matrix);
}

int		smister(t_cmds *esterna, t_h *h)
{
	char	**tmpcmd;
	int		i;
	int		k;

	i = 0;
	while (esterna->comand[i])
	{
		if (esterna->comand[i] != NULL)
		{
			k = 0;
			tmpcmd = sort_list(esterna->comand[i]);
			while (tmpcmd[k])
			{
				gestor_cmd(tmpcmd, k, h);
				k++;
			}
			free_arr(tmpcmd);
		}
		i++;
	}
	return (1);
}
