/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgiovo <sgiovo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 14:06:57 by forsili           #+#    #+#             */
/*   Updated: 2021/03/09 15:25:42 by sgiovo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_syscall(char **s, t_h *h, int k)
{
	char	**argv;
	char	*cmd;
	int		i;
	int		pid;

	s[k] = ft_strtrim(s[k], " ");
	argv = ft_split(s[k], ' ');
	i = 0;
	ourturn_father(h, 0, argv[0], argv);
	pid = fork();
	if (pid == 0)
	{
		open_pipes(h, k);
		open_redirection(h, k);
		open_double_redir(h, k, s);
		exec_cmd(h, 0, cmd, argv);
		close_doubel_redir(h, k, s);
		close_redirection(h, k, s);
		close_pipeson(h, k);
		exit(0);
	}
	close_allfather(h, k);
	close_doubel_redir(h, k, s);
	close_redirection(h, k, s);
	wait(NULL);
	return (k);
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

void	put_usrname(char *str)
{
	char	directory[FT_PATH_MAX];

	ft_putstr(FCYAN);
	ft_putstr(str);
	ft_putstr("> "FRED);
	ft_putstr(getcwd(directory, FT_PATH_MAX));
	ft_putstr("> "NONE);
}
