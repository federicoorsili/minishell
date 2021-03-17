/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forsili <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 14:26:15 by forsili           #+#    #+#             */
/*   Updated: 2021/03/17 14:44:54 by forsili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_swap_redir(char ***m)
{
	char	**in;
	char	*tmp;
	int		i;

	in = *m;
	i = 0;
	while (in[i])
	{
		if (in[i][0] == '<')
		{
			free(in[i]);
			in[i] = ft_strdup("|");
			tmp = in[i - 1];
			in[i - 1] = ft_strjoin("cat ", in[i + 1]);
			free(in[i + 1]);
			in[i + 1] = ft_strdup(tmp);
			free(tmp);
		}
		i++;
	}
}
