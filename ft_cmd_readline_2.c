/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd_readline_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmalori <dmalori@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 11:56:12 by dmalori           #+#    #+#             */
/*   Updated: 2021/03/16 17:49:26 by dmalori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_exit_readline(t_h *h, int mod)
{
	if (mod == 0 || (mod == 1 && h->buffer[0] == 0))
	{
		disablerawmod();
		write(1, "\n", 1);
		free_exit(h, 0);
	}
}

void	ft_cmd_home(t_h *h)
{
	while (h->cursor != 0)
	{
		h->cursor--;
		write(1, "\b", 1);
	}
}

void	ft_cmd_end(t_h *h)
{
	while (h->buffer[h->cursor] != 0)
	{
		write(1, &h->buffer[h->cursor], 1);
		h->cursor++;
	}
}

void	ft_cmd_invio(t_h *h)
{
	disablerawmod();
	while (h->buffer[h->cursor])
		h->cursor++;
	write(1, "\n", 1);
	h->cursor = 0;
	h->v_cursor = h->v_last_cursor;
}
