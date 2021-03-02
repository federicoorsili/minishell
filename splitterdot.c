/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splitterdot.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forsili <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 16:49:40 by forsili           #+#    #+#             */
/*   Updated: 2021/03/02 18:41:17 by forsili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int     ft_count(const char *s, char c)
{
    int i;
    int count;
    int inside;
    inside = 1;
    i = 0;
    count = 0;
    while (s[i])
    {
        if (s[i] == '\'')
            inside *= -1;
        if (s[i] == c && inside > 0)
            count++;
        i++;
    }
    return (count);
}

char		**ft_splitter(const char *s, char c)
{
	int			i;
	int			n;
	int			sw;
	int			k;
	char		**out;

	i = 0;
	n = ft_count(s, c) + 1;
	sw = 1;
	k = 0;
	printf("%d \n", n);
	if (!(out = malloc((n + 1) * sizeof(char *))))
		return (0);
	while (s[i])
	{
		if (s[i] == '\'')
		{
			sw *= -1;
		}
		if (sw < 0)
		{
			n = i;
			i++;
			while (s[i] != '\'' && s[i])
				i++;
			while (s[i] != c && s[i])
				i++;
			sw *= -1;		
		}
		else
		{
			n = i;
			while (s[i] != c && s[i])
				i++;
		}
		if (s[i] == ';')
			out[k] = ft_substr(s, n, i - 1);
		else
			out[k] = ft_substr(s, n, i);
		k++;
		if (s[i])
			i++;
	}
	out[k] = 0;
	return (out);
}
