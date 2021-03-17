/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ourturn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forsili <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 12:55:06 by sgiovo            #+#    #+#             */
/*   Updated: 2021/03/17 17:06:39 by forsili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		add_assign(t_h *h, char **argv)
{
	int i;

	if (argv[1][0] != '=' && ft_strnstr(argv[1], "=", ft_strlen(argv[1])))
	{
		i = 1;
		while (argv[i] && argv[i][0] != '=' &&
		ft_strnstr(argv[i], "=", ft_strlen(argv[i])))
		{
			h->tmp_env[declarated(h->tmp_env, argv[i])] = ft_strdup(argv[i]);
			i++;
		}
		h->error = errno;
		return ;
	}
}

static int	ourturn_father4(t_h *h, char *cmd, char **argv)
{
	if ((ft_strncmp(argv[0], "export", ft_strlen(argv[0])) == 0) &&
	ft_strlen(argv[0]) == ft_strlen("export"))
	{
		if (argv[1])
		{
			add_assign(h, argv);
			h->error = ft_single_export(h, argv);
		}
		return (0);
	}
	if ((ft_strncmp(argv[0], "exit", ft_strlen(argv[0])) == 0) &&
	ft_strlen(argv[0]) == ft_strlen("exit"))
	{
		if (arr_len(argv) == 1)
			free_exit(h, 0);
		else if (arr_len(argv) == 2 && ft_strdigit(argv[1]))
			free_exit(h, ft_atoi(argv[1]));
		else if (arr_len(argv) > 2 && ft_strdigit(argv[1]))
			free_exit(h, 1);
		else
			free_exit(h, 255);
	}
	cmd = NULL;
	return (0);
}

static int	ourturn_father3(t_h *h, char *cmd, char **argv)
{
	if ((ft_strncmp(argv[0], "unset", ft_strlen(argv[0])) == 0) &&
	ft_strlen(argv[0]) == ft_strlen("unset"))
	{
		if (argv[1])
			h->error = ft_unset_manager(h, argv);
		return (1);
	}
	return (ourturn_father4(h, cmd, argv));
}

static int	ourturn_father2(t_h *h, char *cmd, char **argv)
{
	int i;

	if ((ft_strncmp(argv[0], "stat", ft_strlen(argv[0])) == 0) &&
	ft_strlen(argv[0]) == ft_strlen("stat"))
	{
		i = 0;
		while (h->tmp_env[i])
		{
			printf("%s\n", h->tmp_env[i]);
			i++;
		}
		h->error = errno;
		return (1);
	}
	if ((ft_strncmp(argv[0], "setdir", ft_strlen(argv[0])) == 0) &&
	ft_strlen(argv[0]) == ft_strlen("setdir"))
	{
		h->sw_dir *= -1;
		h->error = errno;
		return (1);
	}
	return (ourturn_father3(h, cmd, argv));
}

int			ourturn_father(t_h *h, char *cmd, char **argv)
{
	int i;

	if ((ft_strncmp(argv[0], "cd", ft_strlen(argv[0])) == 0) &&
	ft_strlen(argv[0]) == ft_strlen("cd"))
	{
		h->error = cd(argv, h);
		if (h->error == 2)
			h->error = 1;
		return (1);
	}
	if (argv[0][0] != '=' && ft_strnstr(argv[0], "=", ft_strlen(argv[0])))
	{
		i = -1;
		while (argv[++i] && argv[i][0] != '=' &&
		ft_strnstr(argv[i], "=", ft_strlen(argv[i])))
		{
			if (declarated(h->our_env, argv[i]) != arr_len(h->our_env))
				h->our_env[declarated(h->our_env, argv[i])] =
					ft_strdup(argv[i]);
			h->tmp_env[declarated(h->tmp_env, argv[i])] = ft_strdup(argv[i]);
		}
		h->error = 0;
		return (1);
	}
	return (ourturn_father2(h, cmd, argv));
}
