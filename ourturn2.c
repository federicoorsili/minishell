/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ourturn2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forsili <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 23:29:58 by forsili           #+#    #+#             */
/*   Updated: 2021/03/13 20:09:58 by forsili          ###   ########.fr       */
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
			return	(i);
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
		//ft_memset(h->tmp_env[i], 0, ft_strlen(h->tmp_env[i]));
		free(h->tmp_env[i]);
		i++;
	}
	while (i < ENV_SIZE)
	{
		free(h->tmp_env[i]);
		i++;
	}
	h->tmp_env = ft_calloc(500, sizeof(char *));
	return (0);
}

char	*src_home(char **tmp)
{
	int		i;
	int		k;
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
	return (out[1]);
}
