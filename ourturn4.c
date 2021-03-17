/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ourturn4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forsili <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 12:09:20 by forsili           #+#    #+#             */
/*   Updated: 2021/03/17 13:24:38 by forsili          ###   ########.fr       */
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

void			write_file(t_h *h, int k)
{
	int i;

	i = 0;
	if (!h->bufred[0])
	{
		write(h->fdred[k], 0, 1);
		return ;
	}
	while (h->bufred[i])
	{
		write(h->fdred[k], &h->bufred[i], 1);
		h->bufred[i] = 0;
		i++;
	}
	write(h->fdred[k], 0, 1);
}

void			ft_print_sort_env(char **env)
{
	int		i;
	int		k;
	char	*tmp;

	i = 0;
	while (env[i] && env[i + 1])
	{
		if (ft_strcmp(env[i], env[i + 1]) > 0)
		{
			tmp = env[i];
			env[i] = env[i + 1];
			env[i + 1] = tmp;
			i = -1;
		}
		i++;
	}
	i = 0;
	while (env[i])
	{
		if (!ft_strnstr(env[i], "?=", ft_strlen("?=")))
		{
			ft_printf("declare -x ");
			k = 0;
			while (env[i][k])
			{
				if (k > 0 && env[i][k] == '=')
				{
					ft_printf("=\"");
				}
				else
					ft_printf("%c", env[i][k]);
				k++;
			}
			ft_printf("\"\n");
			i++;
		}
		else
			i++;
	}
}

void			env_cpy(char **env)
{
	char	*env2[5000];
	int		i;

	i = 0;
	while (env[i])
	{
		env2[i] = env[i];
		i++;
	}
	ft_print_sort_env(env2);
}
