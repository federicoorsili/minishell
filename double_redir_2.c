/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_redir_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forsili <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 10:23:33 by forsili           #+#    #+#             */
/*   Updated: 2021/03/17 10:24:39 by forsili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		count_double_redir_pre(t_h *h, char **tmpcmd)
{
	int k;

	k = 0;
	h->next_redirection = 0;
	while (tmpcmd[k])
	{
		tmpcmd[k] = ft_strtrim(&tmpcmd[k], " ", 1);
		if (k != 0 && tmpcmd[k - 1][0] == '>')
		{
			h->next_redirection += 2;
		}
		if (k < (arr_len(tmpcmd) - 2))
		{
			tmpcmd[k + 2] = ft_strtrim(&tmpcmd[k + 2], " ", 1);
			tmpcmd[k] = ft_strtrim(&tmpcmd[k], " ", 1);
			if (tmpcmd[k + 1][0] == '>')
			{
				h->next_redirection += 1;
			}
		}
		if (h->next_redirection == 3)
			return ;
		k++;
		h->next_redirection = 0;
	}
}

int			pipe_before(char **tmpcmd, int k)
{
	int i;

	i = k;
	while (i >= 0)
	{
		if (tmpcmd[i][0] == '|' && (k - i) == 3)
			return (1);
		i--;
	}
	return (0);
}
