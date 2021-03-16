/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ourturn4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forsili <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 12:09:20 by forsili           #+#    #+#             */
/*   Updated: 2021/03/16 12:13:26 by forsili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		finder(char ***env, char **argv, int i)
{
	int k;

	k = 0;
	while ((*env)[k])
	{
		if (!ft_strncmp((*env)[k], argv[i], ft_strlen(argv[i])))
			break ;
		k++;
	}
	return (k);
}

char			**ft_array_swap(char ***env, char **argv, int i)
{
	int		k;
	int		j;
	int		found;
	char	**tmp;

	found = finder(env, argv, i);
	if ((tmp = ft_calloc(ENV_SIZE, sizeof(char *))))
	{
		k = 0;
		j = 0;
		while ((*env)[k])
		{
			if (j != found)
				tmp[j++] = ft_strdup((*env)[k]);
			else
				found = -1;
			k++;
		}
	}
	else
		return (0);
	free_arr((*env), ENV_SIZE);
	return (tmp);
}
