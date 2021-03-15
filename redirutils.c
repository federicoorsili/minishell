/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirutils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forsili <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 10:24:05 by forsili           #+#    #+#             */
/*   Updated: 2021/03/13 22:14:57 by forsili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		write_file(t_h *h, int k, char *buf)
{
	int i;

	i = 0;
	if (!buf)
	{
		write(h->fdred[k], 0, 1);
		return ;
	}
	while (buf[i])
	{
		write(h->fdred[k], &buf[i], 1);
		h->bufred[i] = 0;
		i++;
	}
	write(h->fdred[k], 0, 1);
}

void		read_file(t_h *h, int k)
{
	char	buf[2];
	int		i;
	int		fd_tmp;

	i = 0;
	if (h->next_redirection == 3)
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
	char	*str;

	h->nredir = 0;
	if (k != 0)
	{
		if (tmpcmd[k - 1][0] == '>' && !tmpcmd[k - 1][1])
		{
			h->nredir += 2;
			h->fdred[k] = open(tmpcmd[k], O_RDWR);
			read_file(h, k);
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

void		open_redirection(t_h *h, int k)
{
	if (h->nredir == 1)
		dup2(h->fdred[k], 1);
	if (h->nredir == 3)
		write_file(h, k, h->bufred);
}

int			close_redirection(t_h *h, int k, char **tmpcmd)
{
	if (h->nredir == 1 || h->nredir == 3)
	{
		close(h->fdred[k]);
	}
	return (k);
}