/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forsili <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 16:50:12 by sgiovo            #+#    #+#             */
/*   Updated: 2021/03/16 11:51:11 by forsili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	crt_env(char **env, t_h *h)
{
	int		i;
	int		k;

	i = 0;
	h->our_env = ft_calloc(ENV_SIZE, sizeof(char *));
	while (env[i])
	{
		k = 0;
		if (!(h->our_env[i] = malloc(ft_strlen(env[i]))))
			return ;
		while (env[i][k])
		{
			h->our_env[i][k] = env[i][k];
			k++;
		}
		h->our_env[i][k] = 0;
		i++;
	}
	h->our_env[i] = 0;
}
