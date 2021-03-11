/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pidutils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgiovo <sgiovo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 10:03:08 by forsili           #+#    #+#             */
/*   Updated: 2021/03/11 14:40:38 by sgiovo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		open_pipes(t_h *h, int k)
{
	if (h->npipes == 1 || h->npipes == 3)
	{
		close(h->pipe[k][0]);
		dup2(h->pipe[k][1], 1);
		if (h->npipes == 3)
		{
			close(h->pipe[k - 2][1]);
			dup2(h->pipe[k - 2][0], 0);
		}
	}
	if (h->npipes == 2)
	{
		close(h->pipe[k - 2][1]);
		dup2(h->pipe[k - 2][0], 0);
	}
}

void	close_pipeson(t_h *h, int k)
{
	if (h->npipes == 1 || h->npipes == 3)
	{
		close(h->pipe[k][1]);
		if (h->npipes == 3)
			close(h->pipe[k - 2][0]);
	}
	if (h->npipes == 2)
		close(h->pipe[k - 2][0]);
}

void	close_allfather(t_h *h, int k)
{
	if (h->npipes == 2 || h->npipes == 3)
	{
		close(h->pipe[k - 2][0]);
		close(h->pipe[k - 2][1]);
	}
}
void	exec_cmd(t_h *h, int i, char *cmd, char **argv)
{
	int err;

	while (h->path[i])
	{
		cmd = ft_strjoin(h->path[i], argv[0]);
		err = execve(cmd, argv, *(h->env));
		i++;
	}
}

void	count_pipes(t_h *h, int k, char **tmpcmd)
{
	h->npipes = 0;
	if (k < (arr_len(tmpcmd) - 1))
	{
		if (tmpcmd[k + 1][0] == '|')
		{
			h->npipes += 1;
			pipe(h->pipe[k]);
		}
	}
	if (k != 0)
	{
		if (tmpcmd[k - 1][0] == '|')
			h->npipes += 2;
	}
}