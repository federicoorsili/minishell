/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmalori <dmalori@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 19:50:14 by forsili           #+#    #+#             */
/*   Updated: 2021/03/14 10:39:14 by dmalori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_exit(t_h *h)
{
	free_arr(h->our_env, ENV_SIZE);
	free_arr(h->tmp_env, ENV_SIZE);
	free_arr(h->path, arr_len(h->path));
	free_arr(h->history, arr_len(h->history));
	free(h->history_path);
	free(h->usr);
}