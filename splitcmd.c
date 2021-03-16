/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splitcmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmalori <dmalori@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 00:40:29 by forsili           #+#    #+#             */
/*   Updated: 2021/03/16 14:27:12 by dmalori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int				ft_strlen_split(char *str, char *charset, int mod)
{
	int i;

	if (!mod)
	{
		i = 0;
		while (str[i] != 0 && ft_iscontain(str[i], charset) == 0)
			i++;
		return (i);
	}
	else
	{
		i = 0;
		while (str[i] != 0 && ft_iscontain(str[i], charset) == 1)
			i++;
		return (i);
	}
}

int				ft_cw(char *str, char *charset)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (str[i] != 0)
	{
		if (ft_iscontain(str[i], charset))
		{
			i += ft_strlen_split(&str[i], charset, 1);
			count++;
		}
		else if (str[i])
		{
			i += ft_strlen_split(&str[i], charset, 0);
			count++;
		}
	}
	return (count);
}

void			ft_insert_word(char *dest, char *src, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
}

static int		ft_loop_split(t_var_split *var, char **m)
{
	if (ft_iscontain(var->str[var->i], var->charset))
	{
		if ((m[var->w_i] = (char *)malloc((ft_strlen_split(&var->str[var->i],
			var->charset, 1) + 1) *
			sizeof(char))) == 0)
			return (0);
		ft_insert_word(m[var->w_i], &var->str[var->i],
			ft_strlen_split(&var->str[var->i], var->charset, 1));
		var->i += ft_strlen_split(&var->str[var->i], var->charset, 1);
		var->w_i++;
	}
	else
	{
		if ((m[var->w_i] = (char *)malloc((ft_strlen_split(&var->str[var->i],
			var->charset, 0) + 1) * sizeof(char))) == 0)
			return (0);
		ft_insert_word(m[var->w_i], &var->str[var->i],
			ft_strlen_split(&var->str[var->i], var->charset, 0));
		var->i += ft_strlen_split(&var->str[var->i], var->charset, 0);
		var->w_i++;
	}
	return (1);
}

char			**ft_split_cmd(char *str, char *charset)
{
	char			**m;
	t_var_split		var;

	ft_memset(&var, 0, sizeof(t_var_split));
	var.str = str;
	var.charset = charset;
	if ((m = (char **)malloc(((ft_cw(str, charset) + 1)) *
		sizeof(char *))) == 0)
		return (0);
	while (var.str[var.i])
		if (!ft_loop_split(&var, m))
			return (NULL);
	m[var.w_i] = 0;
	return (m);
}
