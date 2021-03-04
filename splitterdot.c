/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splitterdot.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forsili <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 16:49:40 by forsili           #+#    #+#             */
/*   Updated: 2021/03/04 13:35:46 by forsili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int     ft_count(const char *s, char c)
{
	int i;
	int count;
	int inside;
	char	apx;

	inside = 1;
	apx = 0;
	i = 0;
	count = 0;
	while (s[i])
	{
		if (((s[i] == '\'' && s[i - 1] != '\\') ||
			(s[i] == '\"' && s[i - 1] != '\\')) && !apx)
		{
			apx = s[i];
			i++;
			inside *= -1;
		}
		if (s[i] == apx && s[i - 1] != '\\' && apx)
			inside *= -1;
		if (s[i] == c && inside > 0)
			count++;
		i++;
	}
	return (count);
}

void		scroller(const char *s, char c, int *i, int *sw, char apx)
{
	int k;

	k = *i;
	while (s[k] != c && s[k])
	{
		if ((s[k] == '\'' && s[k - 1] != '\\') ||
			(s[k] == '"' && s[k - 1] != '\\'))
		{
			apx = s[k];
			*sw *= -1;
			apix_gest(s, c, &k, &*sw, apx);
			*i = k;
			break ;
		}
		k++;
	}
	*i = k;
}

int			apix_gest(const char *s, char c, int *i, int *sw, char apx)
{
	int n;
	int k;

	k = *i;
	n = k;
	k++;
	while (s[k])
	{
		if (s[k] == apx && s[k - 1] != '\\')
		{
			*sw *= -1;
			break ;
		}
		k++;
	}
	if (s[k])
		k++;
	scroller(s, c, &k, &*sw, apx);
	*i = k;
	return (n);
}

char		**ft_splitter(const char *s, char c)
{
	int			i[2];
	int			n;
	int			sw;
	char		apx;
	char		**out;

	i[0] = 0;
	n = ft_count(s, c) + 1;
	sw = 1;
	i[1] = 0;
	if (!(out = malloc((n + 2) * sizeof(char *))))
		return (0);
	while (s[i[0]])
	{
		if ((s[i[0]] == '\'' && s[i[0] - 1] != '\\') ||
			(s[i[0]] == '"' && s[i[0] - 1] != '\\'))
		{
			apx = s[i[0]];
			sw *= -1;
		}
		if (sw < 0)
			n = apix_gest(s, c, &i[0], &sw, apx);
		else
		{
			n = i[0];
			scroller(s, c, &i[0], &sw, apx);
		}
		out[i[1]] = ft_substr(s, n, i[0] - n);
		i[1]++;
		if (s[i[0]])
			i[0]++;
	}
	out[i[1]] = 0;
	if (sw < 0)
	{
		printf("ERROR: apix not closed\n");
		//funzione di pulizia
		exit(0);
	}
	return (out);
}
