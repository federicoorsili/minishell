/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syscall.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forsili <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 14:08:42 by dmalori           #+#    #+#             */
/*   Updated: 2021/03/17 09:54:58 by forsili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	set_error(t_h *h)
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

static void	ft_start_pid(char **s, t_h *h, int k, char **argv)
{
	char *cmd;

	cmd = NULL;
	open_pipes(h, k);
	open_redirection(h, k, s);
	open_double_redir(h, k, s);
	open_revred(h, k, s);
	exec_cmd(h, 0, cmd, argv);
	close_doubel_redir(h, k);
	close_redirection(h, k);
	close_pipeson(h, k);
	if (!h->flag_exit)
		exit(127);
	else
		exit(h->error);
}

static int	ft_pre_ourturn(t_h *h, char **argv)
{
	set_error(h);
	free_arr(argv, arr_len(argv));
	return (1);
}

int			ft_syscall(char **s, t_h *h, int k)
{
	char	**argv;
	char	*cmd;
	int		i;
	pid_t	pid;

	cmd = NULL;
	s[k] = ft_strtrim(&s[k], " ", 1);
	argv = ft_splitter(s[k], " ", 0, h);
	i = 0;
	argv = trim_apx(argv, h);
	if (ourturn_father(h, argv[0], argv))
		return (ft_pre_ourturn(h, argv));
	pid = fork();
	if (pid == 0)
		ft_start_pid(s, h, k, argv);
	h->error = errno;
	close_allfather(h, k);
	close_doubel_redir(h, k);
	close_redirection(h, k);
	wait(&pid);
	free_arr(argv, arr_len(argv));
	h->error = WEXITSTATUS(pid);
	set_error(h);
	return (k);
}
