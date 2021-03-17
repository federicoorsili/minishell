/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forsili <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 19:50:14 by forsili           #+#    #+#             */
/*   Updated: 2021/03/17 09:49:21 by forsili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_exit(t_h *h, int code)
{
	free_arr(h->our_env, ENV_SIZE);
	free_arr(h->tmp_env, ENV_SIZE);
	if (h->path[0])
		free_arr(h->path, arr_len(h->path));
	free_arr(h->history, arr_len(h->history));
	free(h->history_path);
	free(h->usr);
	exit(code);
}
