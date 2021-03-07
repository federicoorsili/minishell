/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splitcmd2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forsili <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 21:55:01 by forsili           #+#    #+#             */
/*   Updated: 2021/03/07 23:03:41 by forsili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exit_call(char c, int i)
{
	int sw;

	sw = 0;
	if (i == 2 && c == '>')
		sw = 1;
	if (i == 1 && (c == '<' || c == '|'))
		sw = 1;
	if (sw)
	{
		printf("ERROR: too many %c\n", c);
		exit(0);
	}
}
char	*separator(char *str, char *out, int *z, int *j)
{
	int i;
	char c;

	i = 0;
	out = malloc(5);
	c = str[*z];
	while(str[*z] == c)
	{
		exit_call(c, i);
		out[i] = str[*z];
		*z += 1;
		i++;
	}
	if (is_in_charset("|<>", str[*z]))
		exit_call('<',1);
	out[i] = 0;
	*j += 1;
	return (out);
}

char	**auxiliary_splitter(char *str, char **arr, char *charset)
{
	char **out;
	int		i;
	char	ch;
	int		j;
	int		z;

	out = malloc((arr_len(arr) * 2) * sizeof (char *));
	i = 0;
	j = 0;
	z = 0;
	if (str[z] && is_in_charset(charset, str[z]))
		out[j] = separator(str, out[j], &z, &j);
	while (arr[i])
	{
		z += ft_strlen(arr[i]);
		out[j] = ft_strdup(arr[i]);
		j++;
		if (str[z] && is_in_charset(charset, str[z]))
			out[j] = separator(str, out[j], &z, &j);
		free(arr[i]);
		i++;
	}
	free(arr);
	out[j] = 0;
	return (out);
}
