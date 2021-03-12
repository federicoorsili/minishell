/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smista.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forsili <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 15:35:27 by forsili           #+#    #+#             */
/*   Updated: 2021/03/11 22:43:40 by forsili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_strnstr_md(char *haystack, char *needle, int len)
{
	size_t index;
	size_t find;

	index = 0;
	find = 0;
	if (needle[index] == 0)
		return (0);
	while (haystack[index] != 0 && index < len)
	{
		find = 0;
		while (haystack[index + find] == needle[find] && index + find < len)
		{
			if (find == ft_strlen(needle) - 1)
				if (haystack[find + 1] == 0)
					return (1);
			find++;
		}
		index++;
	}
	return (0);
}

void	print_env(t_h *h)
{
	int		i;
	char	**tmp;

	tmp = h->our_env;
	i = 0;
	while (tmp[i])
	{
		printf("%s\n", tmp[i]);
		i++;
	}
}

char	**src_path(char **tmp)
{
	int		i;
	int		k;
	char	**out;

	i = 0;
	while (tmp[i])
	{
		if (!ft_strncmp(tmp[i], "PATH=", 5))
			break ;
		i++;
	}
	out = ft_split(tmp[i], '=');
	out = ft_split(out[1], ':');
	i = 0;
	while (out[i])
	{
		out[i] = ft_strjoin(out[i], "/");
		i++;
	}
	return (out);
}

