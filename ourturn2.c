/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ourturn2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmalori <dmalori@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 23:29:58 by forsili           #+#    #+#             */
/*   Updated: 2021/03/16 14:29:20 by dmalori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		declarated(char **env, char *argv)
{
	int i;
	int len;

	len = 0;
	while (argv[len] && argv[len] != '=')
		len++;
	i = 0;
	while (env[i])
	{
		if (!ft_strncmp(env[i], argv, len))
			return (i);
		i++;
	}
	return (i);
}

int		ft_export(t_h *h)
{
	int i;
	int k;

	k = arr_len(h->our_env);
	i = 0;
	while (h->tmp_env[i])
	{
		k = declarated(h->our_env, h->tmp_env[i]);
		h->our_env[k] = ft_strdup(h->tmp_env[i]);
		free(h->tmp_env[i]);
		i++;
	}
	while (i < ENV_SIZE)
	{
		free(h->tmp_env[i]);
		i++;
	}
	h->tmp_env = ft_calloc(ENV_SIZE, sizeof(char *));
	return (0);
}

char	*src_home(char **tmp)
{
	int		i;
	char	**out;

	i = 0;
	while (tmp[i])
	{
		if (!ft_strncmp(tmp[i], "HOME=", 5))
			break ;
		i++;
	}
	out = ft_split(tmp[i], '=');
	free(out[0]);
	free(out);
	return (out[1]);
}

void	mono_export(t_h *h, char **argv, int i, int k)
{
	int j;

	j = declarated(h->our_env, argv[i]);
	if (j != arr_len(h->our_env))
	{
		free(h->our_env[j]);
		h->our_env[j] = ft_strdup(h->tmp_env[k]);
	}
	else
		h->our_env[j] = ft_strdup(h->tmp_env[k]);
	h->tmp_env = ft_array_swap(&h->tmp_env, argv, i);
}

int		ft_single_export(t_h *h, char **argv)
{
	int i;
	int k;

	i = 1;
	while (argv[i])
	{
		k = 0;
		while (h->tmp_env[k])
		{
			if (!ft_strncmp(h->tmp_env[k], argv[i], ft_strlen(argv[i])))
				mono_export(h, argv, i, k);
			k++;
		}
		i++;
	}
	return (0);
}
