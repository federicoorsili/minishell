/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forsili <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 14:36:58 by forsili           #+#    #+#             */
/*   Updated: 2021/03/16 12:24:04 by forsili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		reset_pipe(t_h *h)
{
	h->pipe[0][0] = 0;
	h->pipe[0][1] = 1;
}

int			arr_len(char **arr)
{
	int i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

int			gestor_cmd(char **tmpcmd, int k, t_h *h)
{
	count_pipes(h, k, tmpcmd);
	count_double_redir_pre(h, tmpcmd);
	count_redirection(h, k, tmpcmd);
	count_double_redir(h, k, tmpcmd);
	count_revredir(h, k, tmpcmd);
	if (tmpcmd[k][0] != '|' && tmpcmd[k][0] != '>' && tmpcmd[k][0] != '<')
	{
		ft_syscall(tmpcmd, h, k);
	}
	return (k);
}
