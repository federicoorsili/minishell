/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_redirection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forsili <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 18:55:12 by forsili           #+#    #+#             */
/*   Updated: 2021/03/08 19:07:10 by forsili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	count_revredir(t_h *h, int k, char **tmpcmd)
{
	int i;
	int j;

	i=0;
	while (tmpcmd[k])
	{
		if (k < (arr_len(tmpcmd) - 1))
		{
			if (tmpcmd[k + 1][0] == '<' && !tmpcmd[k + 1][1])
			{
				j = 0;
				while (tmpcmd[k][j])
				{
					h->revred[i][j] = tmpcmd[k][j];
					j++;
				}
				h->revred[i][j] = 0;	
			}
		}
		k += 2;
		i++;
	}
}