/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_redirection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forsili <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 18:55:12 by forsili           #+#    #+#             */
/*   Updated: 2021/03/17 12:46:54 by forsili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	count_revredir(t_h *h, int k, char **tmpcmd)
{
	h->revred = 0;
	if (k != 0)
	{
		if (tmpcmd[k - 1][0] == '<' && !tmpcmd[k - 1][1])
			h->revred += 2;
	}
	if (k < (arr_len(tmpcmd) - 2))
	{
		if (tmpcmd[k + 1][0] == '<' && !tmpcmd[k + 1][1])
			h->revred += 1;
	}
}

void	put_file(t_h *h)
{
	char buf[2];

	while (read(h->fdrev_redirection, &buf, 1))
	{
		write(0, &buf[0], 1);
	}
}

int		last_reverse(t_h *h, int k, char **tmpcmd)
{
	int i;

	i = k + 1;
	while (tmpcmd[i])
	{
		if (tmpcmd[i][0] != '<')
			break ;
		if (tmpcmd[i + 1])
			i += 2;
		else
			break ;
	}
	i--;
	h->fdrev_redirection = open(tmpcmd[i], O_RDWR);
	return (i);
}

void	open_revred(t_h *h, int k, char **tmpcmd)
{
	if (h->revred == 1)
	{
		last_reverse(h, k, tmpcmd);
		if (h->fdrev_redirection >= 0)
			dup2(h->fdrev_redirection, 0);
		else
			exit(2);
	}
}

void	close_revredir(t_h *h)
{
	if (h->revred == 2)
		close(h->fdrev_redirection);
}
