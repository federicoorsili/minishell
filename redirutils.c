/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirutils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forsili <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 10:24:05 by forsili           #+#    #+#             */
/*   Updated: 2021/03/16 11:10:00 by forsili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		write_file(t_h *h, int k)
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

void		read_file(t_h *h, int k, int mod)
{
	char	buf[2];
	int		i;
	int		fd_tmp;

	i = 0;
	if (h->next_redirection == 3 && mod)
	{
		fd_tmp = open(".tmp", O_RDWR);
		while ((read(fd_tmp, buf, 1)) == 1)
		{
			h->bufred[i] = buf[0];
			i++;
		}
		h->bufred[i] = 0;
		close(fd_tmp);
	}
	else
	{
		while ((read(h->fdred[k], buf, 1)) == 1)
		{
			h->bufred[i] = buf[0];
			i++;
		}
		h->bufred[i] = 0;
	}
}

void		      count_redirection(t_h *h, int k, char **tmpcmd)
{
	h->nredir = 0;
	if (k != 0)
	{
		if (tmpcmd[k - 1][0] == '>' && !tmpcmd[k - 1][1])
		{
			h->nredir += 2;
			h->fdred[k] = open(tmpcmd[k], O_RDWR);
			if (h->bufred[0] == 0)
				read_file(h, k, 0);
			if (k < (arr_len(tmpcmd) - 2))
				if (tmpcmd[k + 1][0] == '>')
				{
					close(h->fdred[k]);
					h->fdred[k] = open(tmpcmd[k], O_RDWR | O_CREAT | O_TRUNC, 0755);
				}
			close(h->fdred[k]);
		}
	}
	if (k < (arr_len(tmpcmd) - 2))
	{
		if (tmpcmd[k + 1][0] == '>' && !tmpcmd[k + 1][1])
		{
			h->nredir += 1;
			tmpcmd[k + 2] = ft_strtrim(&tmpcmd[k + 2], " ", 1);
			h->fdred[k] = open(tmpcmd[k + 2], O_RDWR | O_CREAT | O_TRUNC, 0755);
		}
	}
	if (k == 0 && tmpcmd[k][0] == '>' && !tmpcmd[k][1])
	{
		tmpcmd[k + 1] = ft_strtrim(&tmpcmd[k + 1], " ", 1);
		h->fdred[k] = open(tmpcmd[k + 1], O_RDWR | O_CREAT | O_TRUNC, 0755);
		close(h->fdred[k]);
	}
}

void		open_redirection(t_h *h, int k, char **tmpcmd)
{
	if (h->nredir == 1)
		dup2(h->fdred[k], 1);
	if (h->nredir == 2 && h->ndoubler == 0)
	{
		h->fdred[k] = open(tmpcmd[k], O_RDWR | O_CREAT | O_TRUNC, 0755);
		write_file(h, k);
	}
}

int			close_redirection(t_h *h, int k)
{
	if (h->nredir == 1 || h->nredir == 3)
	{
		close(h->fdred[k]);
	}
	return (k);
}