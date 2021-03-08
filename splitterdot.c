/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splitterdot.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forsili <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 16:49:40 by forsili           #+#    #+#             */
/*   Updated: 2021/03/08 17:15:22 by forsili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		backslash(int *sw, int i, const char *s, char *apx)
{
	int k;
	int count;

	k = i - 1;
	count = 0;
	*apx = s[i];
	while (s[k] == '\\')
	{
		count++;
		k--;
	}
	if ((count % 2) == 0)
	{
		*sw *= -1;
	}
}

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
		if (((s[i] == '\'' || s[i] == '"') && (i == 0 || s[i - 1] != '\\')) && !apx)
		{
			apx = s[i];
			i++;
			inside *= -1;
		}
		else if (((s[i] == '\'' || s[i] == '"') && s[i - 1] == '\\') && !apx)
			backslash(&inside, i, s, &apx);
		if (s[i] == apx && (i == 0 || s[i - 1] != '\\') && apx)
			inside *= -1;
		else if (s[i] == apx && (i == 0 || s[i - 1] == '\\') && apx)
			backslash(&inside, i, s, &apx);
		if (s[i] == c && inside > 0)
			count++;
		i++;
	}
	return (count);
}

void		scroller(const char *s, char c, int *i, int *sw, char *apx)
{
	int k;

	k = *i;
	while (s[k] != c && s[k])
	{
		if (((s[k] == '\'' || s[k] == '"') && (k == 0 || s[k - 1] != '\\')))
		{
			*apx = s[k];
			*sw *= -1;
			k++;
			apix_gest(s, c, &k, &*sw, apx);
			*i = k;
			break ;
		}
		else if ((s[k] == '\'' && s[k - 1] == '\\') ||
			(s[k] == '"' && s[k - 1] == '\\'))
		{
			backslash(&*sw, *i, s, apx);
			if (*sw < 0)
			{
				k++;
				apix_gest(s, c, &k, &*sw, apx);
				*i = k;
				printf("ciao2\n");
				break ;
			}
		}
		k++;
	}
	*i = k;
}

int			apix_gest(const char *s, char c, int *i, int *sw, char *apx)
{
	int n;
	int k;

	k = *i;
	n = k - 1;
	while (s[k])
	{
		if (s[k] == *apx && s[k - 1] != '\\')
		{
			*sw *= -1;
			break ;
		}
		else if (s[k] == *apx && s[k - 1] == '\\')
		{
			backslash(sw, k, s, apx);
			if (sw > 0)
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

		if (s[i[0]] == '\'' || s[i[0]] == '"')
		{
			if (i[0] == 0 || s[i[0] - 1] != '\\')
			{
				apx = s[i[0]];
				sw *= -1;
			}
			else
				backslash(&sw, i[0], s, &apx);
		}
		if (sw < 0)
		{
			printf("ciao %d %c\n", sw, apx);
			i[0]++;
			n = apix_gest(s, c, &i[0], &sw, &apx);
		}
		else
		{
			n = i[0];
			scroller(s, c, &i[0], &sw, &apx);
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
