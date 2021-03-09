/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_redirection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forsili <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 18:55:12 by forsili           #+#    #+#             */
/*   Updated: 2021/03/09 15:23:06 by forsili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*fill_buff(t_h *h, int k, char **tmpcmd, int i)
{
	int fd;

	if (tmpcmd[k])
		k -= 2;
	else if (!tmpcmd[k])
		k--;
	tmpcmd[i] = ft_strjoin(tmpcmd[i], " ");
	tmpcmd[i] = ft_strjoin(tmpcmd[i], tmpcmd[k]);
	return (tmpcmd[i]);
}

char	*error_reverdir(t_h *h, int k, char **tmpcmd, int i)
{
	h->revred = k;
	printf("ERRORE: file does not exist\n");
	return (tmpcmd[i]);
}

char	*count_revredir(t_h *h, int k, char **tmpcmd)
{
	int i;
	int j;
	int	fd;

	i = k;
	h->revred = 0;
	if (tmpcmd[k + 1])
		k++;
	else
		return (tmpcmd[i]);
	while (tmpcmd[k] && tmpcmd[k][0] == '<' && !tmpcmd[k][1])
	{
		tmpcmd[k + 1] = ft_strtrim(tmpcmd[k + 1], " ");
		fd = open(tmpcmd[k + 1], O_RDONLY, 0755);
		close(fd);
		if (fd < 0)
			return (error_reverdir(h, k, tmpcmd, i));
		if (tmpcmd[k] && tmpcmd[k + 1])
			k += 2;
		else
			break ;
	}
	return (fill_buff(h, k, tmpcmd, i));
}
