/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forsili <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 14:36:58 by forsili           #+#    #+#             */
/*   Updated: 2021/03/05 18:47:19 by forsili          ###   ########.fr       */
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

void		gestor_cmd(char **tmpcmd, int k, t_h *h)
{
	static int pip[1200];
	static int sw;

	h->npipes = 0;
	if (k < (arr_len(tmpcmd) - 1))
	{
		if (tmpcmd[k + 1][0] == '|')
		{
			h->npipes += 1;
			pip[k] = 1;
			pipe(h->pipe[k]);
		}
	}
	if (k != 0)
	{
		if (tmpcmd[k - 1][0] != '|' && tmpcmd[k][0] != '|' && k > 3)
			pip[k - 3] = -1;
		else if (tmpcmd[k - 1][0] == '|')
		{
			pip[k - 1]--;
			h->npipes += 2;
		}
	}
	if (tmpcmd[k][0] != '|')
		ft_syscall(tmpcmd[k], h, pip, k);
}
