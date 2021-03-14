/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_var.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmalori <dmalori@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 00:28:41 by forsili           #+#    #+#             */
/*   Updated: 2021/03/14 15:24:24 by dmalori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			src_var(char **tmp, char *src)
{
	int		i;
	int		k;

	i = 0;
	while (tmp[i])
	{
		if (!ft_strncmp(tmp[i], src, ft_strlen(src)))
			break ;
		i++;
	}
	return (i);
}

char		*maker(t_h *h, char *src)
{
	int		i;
	int		k;
	int		sw;

	i = src_var(h->our_env, src);
	sw = 0;
	k = 0;
	if (i == arr_len(h->our_env))
	{
		i = src_var(h->tmp_env, src);
		if (i == arr_len(h->tmp_env))
			return (0);
		sw = 1;
	}
	if (!sw)
	{
		while (h->our_env[i][k] && h->our_env[i][k] != '=')
			k++;
		return (ft_substr(h->our_env[i], k + 1, ft_strlen(h->our_env[i])));
	}
	while (h->tmp_env[i][k] && h->tmp_env[i][k] != '=')
		k++;
	return (ft_substr(h->tmp_env[i], k + 1, ft_strlen(h->tmp_env[i])));
	//GESTIRE ASSENZA DI VARIABILE
}

char		*expand(t_h *h, char *s, int k)
{
	int		i;
	char	*tmp1;
	char	*tmp2;
	char	*expanded;
	char	*out;

	i = k;
	while (s[i] && s[i] != ' ' && s[i] != '"')
		i++;
	tmp1 = ft_substr(s, 0, k);
	tmp2 = ft_substr(s, i, (ft_strlen(s) - i));
	out = ft_substr(s, k + 1, (i - k) - 1);
	expanded = maker(h, out);
	free(out);
	if (expanded)
		out = ft_strjoin(tmp1, expanded);
	else
		out = ft_strdup(tmp1);
	free(tmp1);
	free(expanded);
	tmp1 = out;
	out = ft_strjoin(out, tmp2);
	free(tmp1);
	free(tmp2);
	return (out);
}

char		**expand_var(t_h *h, char **argv)
{
	int		i;
	int		k;

	i = 0;
	while (argv[i])
	{
		k = 0;
		while (argv[i][k])
		{
			if (argv[i][k] == '\'')
			{
				k++;
				while (argv[i][k] && argv[i][k] != '\'')
					k++;
			}
			else if (argv[i][k] == '$')
			{
				argv[i] = expand(h, argv[i], k);
			}
			k++;
		}
		i++;
	}
	return (argv);
}
