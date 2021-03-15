/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_redir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forsili <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 21:50:00 by forsili           #+#    #+#             */
/*   Updated: 2021/03/15 14:23:51 by forsili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		count_double_redir_pre(t_h *h, char **tmpcmd)
{
	int k;

	k = 0;
	h->next_redirection = 0;
	while(tmpcmd[k])
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
			return;
		k++;
		h->next_redirection = 0;
	}
}

void		count_double_redir(t_h *h, int k, char **tmpcmd)
{
	h->ndoubler = 0;
	tmpcmd[k] = ft_strtrim(&tmpcmd[k], " ", 1);
	if (k != 0 && tmpcmd[k - 1][0] == '>' && tmpcmd[k - 1][1] == '>' && !tmpcmd[k - 1][2])
	{
		h->ndoubler += 2;
		h->fdred[k] = open(tmpcmd[k], O_RDWR);
		if (h->bufred[0] == 0)
			read_file(h, k, 1);
		close(h->fdred[k]);
	}
	if (k < (arr_len(tmpcmd) - 2))
	{
		tmpcmd[k + 2] = ft_strtrim(&tmpcmd[k + 2], " ", 1);
		tmpcmd[k] = ft_strtrim(&tmpcmd[k], " ", 1);
		if (tmpcmd[k + 1][0] == '>' && tmpcmd[k + 1][1] == '>' && !tmpcmd[k + 1][2])
		{
			h->ndoubler += 1;
			h->fdred[k] = open(tmpcmd[k + 2], O_RDWR | O_CREAT | O_APPEND, 0755);
		}
	}
	if (k == 0 && tmpcmd[k][0] == '>' && tmpcmd[k][1] == '>' && !tmpcmd[k][2])
	{
		tmpcmd[k + 1] = ft_strtrim(&tmpcmd[k + 1], " ", 1);
		h->fdred[k] = open(tmpcmd[k + 1], O_RDWR | O_CREAT | O_APPEND, 0755);
		close(h->fdred[k]);
	}
}

void		open_double_redir(t_h *h, int k, char**tmpcmd)
{
	if (h->ndoubler == 1)
	{
		if (h->next_redirection != 3)
			dup2(h->fdred[k], 1);
		else
		{
			h->fdred[k] = open(".tmp", O_RDWR | O_CREAT | O_TRUNC, 0755);		
			dup2(h->fdred[k], 1);
		}
	}
	if (h->ndoubler == 2 && h->nredir == 0 && k != 2)
	{
		h->fdred[k] = open(tmpcmd[k], O_RDWR | O_CREAT | O_APPEND, 0755);
		write_file(h, k);
	}
}

int			close_doubel_redir(t_h *h, int k, char **tmpcmd)
{
	if (h->ndoubler != 0)
	{
		close(h->fdred[k]);
	}
	return (k);
}