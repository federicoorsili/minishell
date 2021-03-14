/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ourturn3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmalori <dmalori@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 13:35:45 by sgiovo            #+#    #+#             */
/*   Updated: 2021/03/14 15:55:34 by dmalori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_check_unset(t_h *h, char **argv, int i)
{
	int j;
	int sw;

	sw = 0;
	j = declarated(h->our_env, argv[i]);
	if (j == arr_len(h->our_env))
	{
		j = declarated(h->tmp_env, argv[i]);
		sw = 1;
		if (j == arr_len(h->tmp_env))
			return ;
	}
	if (!sw)
		h->our_env = ft_array_swap(&h->our_env, argv, i);
	else
		h->tmp_env = ft_array_swap(&h->tmp_env, argv, i);
	//printf("io ci sono!\n");
}

int		ft_unset_manager(t_h *h, char **argv)
{
	int i;
	int k;

	i = 1;
	while (argv[i])
	{
		ft_check_unset(h, argv, i);
		i++;
	}
}
