/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirutils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forsili <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 10:24:05 by forsili           #+#    #+#             */
/*   Updated: 2021/03/06 12:03:53 by forsili          ###   ########.fr       */
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
		i++;
	}
	write(h->fdred[k], 0, 1);
}

void		read_file(t_h *h, int k)
{
	char	buf[2];
	int		i;

	i = 0;
	while ((read(h->fdred[k], buf, 1)) == 1)
	{
		h->bufred[i] = buf[0];
		i++;
	}
	h->bufred[i] = 0;
}

void		count_redirection(t_h *h, int k, char **tmpcmd)
{
	h->nredir = 0;
	if (k != 0)
	{
		if (tmpcmd[k - 1][0] == '>' && !tmpcmd[k - 1][1])
		{
			h->nredir += 2;
			h->fdred[k] = open(tmpcmd[k], O_RDWR);
			read_file(h, k);
			if (k < (arr_len(tmpcmd) - 2))
				if (tmpcmd[k + 1][0] == '>' && !tmpcmd[k + 1][1])
				{
					close(h->fdred[k]);
					h->fdred[k] = open(tmpcmd[k], O_RDWR | O_CREAT | O_TRUNC);
				}
			close(h->fdred[k]);
		}
	}
	if (k < (arr_len(tmpcmd) - 2))
	{
		if (tmpcmd[k + 1][0] == '>' && !tmpcmd[k + 1][1])
		{
			h->nredir += 1;
			tmpcmd[k + 2] = ft_strtrim(tmpcmd[k + 2], " ");
			h->fdred[k] = open(tmpcmd[k + 2], O_RDWR | O_CREAT | O_TRUNC);
		}
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