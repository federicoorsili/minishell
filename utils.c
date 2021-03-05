/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forsili <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 14:06:57 by forsili           #+#    #+#             */
/*   Updated: 2021/03/05 18:46:40 by forsili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_syscall(char *s, t_h *h, int pip[1200], int k)
{
	char	**argv;
	char	*cmd;
	int		i;
	int		pid;

	s = ft_strtrim(s, " ");
	argv = ft_split(s, ' ');
	i = 0;
	pid = fork();
	if (pid == 0)
	{
		if (h->npipes == 1 || h->npipes == 3)
		{
			close(h->pipe[k][0]);
			dup2(h->pipe[k][1], 1);
			printf("ooooooo\n");
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
		while (h->path[i])
		{
			cmd = ft_strjoin(h->path[i], argv[0]);
			execve(cmd, argv, *(h->env));
			i++;
		}
		if (h->npipes == 1)
			close(h->pipe[k][1]);
		if (h->npipes == 3)
		{
			close(h->pipe[k][1]);
			close(h->pipe[k - 2][0]);
		}
		if (h->npipes == 2)
			close(h->pipe[k - 2][0]);
		exit(0);
	}
	else
	{
		if (h->npipes == 2 || h->npipes == 3)
		{
			close(h->pipe[k - 2][0]);
			close(h->pipe[k - 2][1]);
		}
		wait(NULL);
	}
}

char	**free_arr(char **arr)
{
	int i;
	int k;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (arr);
}

char	*src_usr(char **tmp)
{
	int		i;
	int		k;
	char	**out;

	i = 0;
	while (tmp[i])
	{
		if (!ft_strncmp(tmp[i], "LOGNAME=", 8))
			break ;
		i++;
	}
	out = ft_split(tmp[i], '=');
	free(out[0]);
	return (out[1]);
}

void	put_usrname(t_h *h)
{
	ft_putstr(FCYAN);
	ft_putstr(h->usr);
	ft_putstr("> "FRED);
}
