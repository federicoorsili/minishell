/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splitcmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forsili <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 00:40:29 by forsili           #+#    #+#             */
/*   Updated: 2021/03/02 14:49:35 by forsili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		check_char(char *s, char c)
{
	int i;

	i = 0;
	while (s[i])
		if (c == s[i++])
			return (0);
	return (1);
}

int		wordcount(char *str, char *charset)
{
	int i;
	int start;
	int words;

	i = 0;
	words = 0;
	start = 0;
	while (str[i])
	{
		if (check_char(charset, str[i]))
		{
			if (start == 0)
			{
				words++;
				start++;
			}
		}
		else if (!check_char(charset, str[i]) && start != 0)
			start = 0;
		i++;
	}
	return (words);
}

void	finder(char *str, char *charset, int *indexarr, int *lenghtarr)
{
	int k;
	int start;
	int i;

	k = 0;
	i = 0;
	while (str[i])
	{
		if (check_char(charset, str[i]) && start == 0)
		{
			indexarr[k] = i;
			lenghtarr[k] += 1;
			start = 1;
		}
		else if (check_char(charset, str[i]) && start != 0)
			lenghtarr[k] += 1;
		else if (!check_char(charset, str[i]) && start != 0)
		{
			start = 0;
			k++;
		}
		i++;
	}
}

char	**solver(char *str, int *lenghtarr, int *indexarr, int lenght)
{
	int		i;
	int		k;
	char	**newarr;
	int		n;

	newarr = (char**)malloc(sizeof(char*) * lenght + 1);
	i = 0;
	while (i < lenght)
	{
		k = 0;
		newarr[i] = (char*)malloc((sizeof(char) * lenghtarr[i]) + 2);
		while (k < lenghtarr[i])
		{
			n = indexarr[i] + k;
			newarr[i][k] = str[n];
			k++;
		}
		while ((str[indexarr[i] + k]) && (str[indexarr[i] + k] == '|' ||
		str[indexarr[i] + k] == '<' || str[indexarr[i] + k] == '>'))
		{
			newarr[i][k] = str[indexarr[i] + k];
			k++;
		}
		newarr[i][k] = '\0';
		i++;
	}
	newarr[i] = 0;
	return (newarr);
}

char	**splitter(char **arr)
{
	int		i[2];
	int		k;
	int		j;
	int		len;
	char	**out;

	i[0] = 0;
	while (arr[i[0]])
		i[0]++;
	if (!(out = malloc(sizeof(char *) * ((i[0] + 1) * 2))))
		return (0);
	len = i[0];
	i[0] = 0;
	i[1] = 0;
	while (arr[i[0]])
	{
		k = 0;
		j = 0;
		while (arr[i[0]][k])
		{
			if ((arr[i[0]][k] == '|' || arr[i[0]][k] == '>' ||
				arr[i[0]][k] == '<'))
				break ;
			k++;
			j++;
		}
		out[i[1]] = ft_substr(arr[i[0]], 0, j);
		i[1]++;
		if (arr[i[0]][j] != 0)
		{
			out[i[1]] = ft_substr(arr[i[0]], j, ft_strlen(arr[i[0]]));
			i[1]++;
		}
		free(arr[i[0]]);
		i[0]++;
	}
	out[i[1]] = 0;
	free(arr);
	return (out);
}

char	**ft_split_cmd(char *str, char *charset)
{
	int		*indexarr;
	int		*lenghtarr;
	char	**arr;
	int		lenght;
	int		i;

	i = 0;
	lenght = wordcount(str, charset);
	indexarr = malloc(sizeof(int*) * lenght);
	lenghtarr = malloc(sizeof(int*) * lenght);
	while (i < lenght)
	{
		indexarr[i] = 0;
		lenghtarr[i++] = 0;
	}
	i = 0;
	finder(str, charset, indexarr, lenghtarr);
	arr = solver(str, lenghtarr, indexarr, lenght);
	return (splitter(arr));
}
