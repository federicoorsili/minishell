/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forsili <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 14:06:57 by forsili           #+#    #+#             */
/*   Updated: 2021/03/13 20:11:03 by forsili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_syscall(char **s, t_h *h, int k)
{
	char	**argv;
	char	*cmd;
	int		i;
	pid_t	pid;

	s[k] = ft_strtrim(s[k], " ");
	argv = ft_splitter(s[k], ' ');
	i = 0;
	argv = trim_apx(argv);
	//argv = expand_var(h, argv);
	if (ourturn_father(h, argv[0], argv))
		return (1);
	pid = fork();
	if (pid == 0)
	{
		open_pipes(h, k);
		open_redirection(h, k);
		open_double_redir(h, k, s);
		exec_cmd(h, 0, cmd, argv);
		printf("%d\n", errno);
		close_doubel_redir(h, k, s);
		close_redirection(h, k, s);
		close_pipeson(h, k);
		exit(0);
	}
	close_allfather(h, k);
	close_doubel_redir(h, k, s);
	close_redirection(h, k, s);
	wait(&pid);
	h->error = errno;
	return (k);
}

char	**free_arr(char **arr, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		free(arr[i]);
		i++;
	}
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

void	put_usrname(char *str, t_h *h)
{
	char	directory[FT_PATH_MAX];

	if (h->error != 0)
	{
		ft_putstr(FRED);
		ft_printf("(x|%d)", h->error);
	}
	else
		ft_putstr(FGREEN"(v)");
	ft_putstr(NONE);
	ft_putstr(FCYAN);
	ft_putstr(str);
	ft_putstr(FPURPLE);
	ft_putstr(getcwd(directory, FT_PATH_MAX));
	ft_putstr("> "NONE);
	h->error = 0;
}
