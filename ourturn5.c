/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ourturn5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forsili <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 14:59:55 by forsili           #+#    #+#             */
/*   Updated: 2021/03/17 15:10:01 by forsili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

int				ft_print_env(t_h *h, int mod)
{
	int		i;
	char	**envmtrx;

	i = 0;
	envmtrx = h->our_env;
	if (mod)
	{
		env_cpy(envmtrx);
		return (0);
	}
	while (envmtrx[i])
	{
		if (!ft_strnstr(envmtrx[i], "?=", ft_strlen("?=")) &&
			ft_strlen(envmtrx[i]) != 0)
			ft_printf("%s\n", envmtrx[i++]);
		else
			i++;
	}
	return (0);
}

char			*ret_loop_apix(int j, char buff[1000])
{
	buff[j] = 0;
	if (j == 0)
		return (ft_strdup(""));
	return (ft_strdup(buff));
}
