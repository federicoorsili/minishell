/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pidutils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forsili <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 10:03:08 by forsili           #+#    #+#             */
/*   Updated: 2021/03/17 14:54:31 by forsili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		set_flag_exit(t_h *h, int mod)
{
	if ((h->revred != 0 || h->nredir != 0 || h->npipes != 0 ||
	h->ndoubler != 0 || mod))
		h->flag_exit = 1;
}

static int	exec_cmd3(t_h *h, char **argv)
{
	if ((ft_strncmp(argv[0], "env", ft_strlen(argv[0])) == 0) &&
	ft_strlen(argv[0]) == ft_strlen("env"))
	{
		h->error = ft_print_env(h, 0);
		set_flag_exit(h, 1);
		return (1);
	}
	else if ((ft_strncmp(argv[0], "echo", ft_strlen(argv[0])) == 0) &&
	ft_strlen(argv[0]) == ft_strlen("echo"))
	{
		echo_manager(argv);
		h->error = 0;
		set_flag_exit(h, 1);
		return (1);
	}
	return (0);
}

static int	exec_cmd2(t_h *h, char **argv)
{
	if ((ft_strncmp(argv[0], "pwd", ft_strlen(argv[0])) == 0) &&
	ft_strlen(argv[0]) == ft_strlen("pwd"))
	{
		h->error = ft_get_pwd();
		set_flag_exit(h, 1);
		return (1);
	}
	else if ((ft_strncmp(argv[0], "export", ft_strlen(argv[0])) == 0) &&
	ft_strlen(argv[0]) == ft_strlen("export"))
	{
		if (!argv[1])
			ft_print_env(h, 1);
		else
		{
			add_assign(h, argv);
			h->error = ft_single_export(h, argv);
		}
		set_flag_exit(h, 1);
		return (1);
	}
	return (exec_cmd3(h, argv));
}

void		exec_cmd(t_h *h, int i, char *cmd, char **argv)
{
	int err;

	h->flag_exit = 0;
	if (exec_cmd2(h, argv))
		return ;
	if (h->path)
	{
		while (h->path[i])
		{
			cmd = ft_strjoin(h->path[i], argv[0]);
			err = execve(cmd, argv, h->our_env);
			i++;
		}
	}
	cmd = argv[0];
	err = execve(cmd, argv, h->our_env);
	if ((h->revred != 0 || h->nredir != 0 || h->npipes != 0 ||
	h->ndoubler != 0))
		h->flag_exit = 1;
}
