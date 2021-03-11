/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgiovo <sgiovo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 16:50:12 by sgiovo            #+#    #+#             */
/*   Updated: 2021/03/11 18:27:15 by sgiovo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	***crt_env(char ***env, t_h *h)
{
	int		i;
	char	***ourenv;

	i = 0;
	ourenv = ft_calloc(1, sizeof(char **));
	ourenv[0] = ft_calloc(500, sizeof(char *));
	while (env[0][i])
	{
		ourenv[0][i] = env[0][i];
		i++;
	}
	ourenv[0][i] = 0;
	return (ourenv);
}
