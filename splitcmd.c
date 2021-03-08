/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splitcmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forsili <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 00:40:29 by forsili           #+#    #+#             */
/*   Updated: 2021/03/08 13:07:12 by forsili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			ft_is_sep(char c, char *charset)
{
	int		i;

	i = 0;
	while (charset[i] != 0)
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int			ft_strlen_split(char *str, char *charset, int mod)
{
	int i;

	if (!mod)
	{
		i = 0;
		while (str[i] != 0 && ft_is_sep(str[i], charset) == 0)
			i++;
		return (i);
	}
	else
	{
		i = 0;
		while (str[i] != 0 && ft_is_sep(str[i], charset) == 1)
			i++;
		return (i);
	}
}

int			ft_cw(char *str, char *charset)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (str[i] != 0)
	{
		if (ft_is_sep(str[i], charset))
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

void		ft_insert_word(char *dest, char *src, int size)
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

char		**ft_split_cmd(char *str, char *charset)
{
	char	**m;
	int		i;
	int		w_i;

	i = 0;
	w_i = 0;
	if ((m = (char **)malloc(((ft_cw(str, charset) + 1)) * sizeof(char *))) == 0)
		return (0);
	while (str[i])
	{
		if (ft_is_sep(str[i], charset))
		{
			if ((m[w_i] = (char *)malloc((ft_strlen_split(&str[i], charset, 1) + 1) *
				sizeof(char))) == 0)
				return (0);
			ft_insert_word(m[w_i], &str[i], ft_strlen_split(&str[i], charset, 1));
			i += ft_strlen_split(&str[i], charset, 1);
			w_i++;
		}
		else
		{
			if ((m[w_i] = (char *)malloc((ft_strlen_split(&str[i], charset, 0) + 1) *
				sizeof(char))) == 0)
				return (0);
			ft_insert_word(m[w_i], &str[i], ft_strlen_split(&str[i], charset, 0));
			i += ft_strlen_split(&str[i], charset, 0);
			w_i++;
		}
	}
	m[w_i] = 0;
	return (m);
}
