/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forsili <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 14:06:57 by forsili           #+#    #+#             */
/*   Updated: 2021/03/15 21:59:45 by forsili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	set_error(t_h *h)
{
	char	*cmd;
	char	*tmp;

	tmp = ft_itoa(h->error);
	cmd = ft_strjoin("?=", tmp);
	free(tmp);
	free(h->our_env[declarated(h->our_env, cmd)]);
	h->our_env[declarated(h->our_env, cmd)] = ft_strdup(cmd);
	free(cmd);
}

int		ft_syscall(char **s, t_h *h, int k)
{
	char	**argv;
	char	*cmd;
	int		i;
	pid_t	pid;

	s[k] = ft_strtrim(&s[k], " ", 1);
	argv = ft_splitter(s[k], " ");
	i = 0;
	argv = trim_apx(argv);
	//argv = expand_var(h, argv);
	if (ourturn_father(h, argv[0], argv))
	{
		set_error(h);
		free_arr(argv, arr_len(argv));
		return (1);
	}
	pid = fork();
	if (pid == 0)
	{
		open_pipes(h, k);
		open_redirection(h, k, s);
		open_double_redir(h, k, s);
		open_revred(h, k, s);
		exec_cmd(h, 0, cmd, argv);
		//printf("%d\n", errno);
		//close_revredir(h);
		close_doubel_redir(h, k, s);
		close_redirection(h, k, s);
		close_pipeson(h, k);
		if (!h->flag_exit)
			exit(127);
		else
			exit(h->error);
	}
	h->error = errno;
	close_allfather(h, k);
	close_doubel_redir(h, k, s);
	//close_redirection(h, k, s);
	close_revredir(h);
	wait(&pid);
	free_arr(argv, arr_len(argv));
	h->error = WEXITSTATUS(pid);
	set_error(h);
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
	free(arr[i]);
	free(arr);
	return (arr);
}

void	src_usr(char **tmp, t_h *h)
{
	int		i;
	int		k;
	char	**out;

	i = 0;
	free(h->usr);
	while (tmp[i])
	{
		if (!ft_strncmp(tmp[i], "LOGNAME=", 8))
			break ;
		i++;
	}
	out = ft_split(tmp[i], '=');
	h->usr = ft_strdup(out[1]);
	free_arr(out, arr_len(out));
}

void	put_usrname(char *str, t_h *h)
{
	char	directory[FT_PATH_MAX];

	if (h->error != 0)
	{
		ft_putstr(FRED);
		ft_printf("[%.3d]", h->error);
	}
	else
		ft_putstr(FGREEN"[000]");
	ft_putstr(NONE);
	ft_putstr(FCYAN);
	ft_putstr(str);
	ft_putstr(FPURPLE);
	ft_putstr(getcwd(directory, FT_PATH_MAX));
	ft_putstr("> "NONE);
	h->error = 0;
}
