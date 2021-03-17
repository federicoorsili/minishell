/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ourturn3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forsili <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 13:35:45 by sgiovo            #+#    #+#             */
/*   Updated: 2021/03/17 09:35:33 by forsili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_check_unset(t_h *h, char **argv, int i)
{
	int j;
	int sw;

	sw = 0;
	j = declarated(h->our_env, argv[i]);
	if (j == arr_len(h->our_env))
	{
		j = declarated(h->tmp_env, argv[i]);
		sw = 1;
		if (j == arr_len(h->tmp_env))
			return ;
	}
	if (!sw)
		h->our_env = ft_array_swap(&h->our_env, argv, i);
	else
		h->tmp_env = ft_array_swap(&h->tmp_env, argv, i);
}

int			ft_unset_manager(t_h *h, char **argv)
{
	int i;

	i = 1;
	while (argv[i])
	{
		ft_check_unset(h, argv, i);
		i++;
	}
	return (0);
}

static void	set_pwd(t_h *h, char *var)
{
	char *tmp;
	char *tmp2;
	char buff[1000];

	tmp = ft_strjoin(var, getcwd(buff, 1000));
	tmp2 = h->our_env[declarated(h->our_env, tmp)];
	h->our_env[declarated(h->our_env, tmp)] = ft_strdup(tmp);
	free(tmp2);
	free(tmp);
}

int			cd(char **argv, t_h *h)
{
	char *tmp;

	errno = 0;
	set_pwd(h, "OLDPWD=");
	if (!argv[1])
	{
		tmp = src_home(h->our_env);
		chdir(tmp);
		free(tmp);
		set_pwd(h, "PWD=");
		return (errno);
	}
	chdir(argv[1]);
	set_pwd(h, "PWD=");
	return (errno);
}

int			ft_get_pwd(void)
{
	char	path[4096];

	errno = 0;
	getcwd(path, FT_PATH_MAX);
	ft_printf("%s\n", path);
	return (errno);
}
