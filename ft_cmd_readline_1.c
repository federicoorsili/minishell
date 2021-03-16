/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd_readline_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmalori <dmalori@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 11:56:12 by dmalori           #+#    #+#             */
/*   Updated: 2021/03/16 12:23:32 by dmalori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_stamp_char(t_h *h, int temp)
{
	if (h->buffer[h->cursor])
		swap_buffer(h, temp, h->cursor);
	else
	{
		h->buffer[h->cursor++] = temp;
		write(1, &temp, 1);
	}
}

void	ft_del_char(t_h *h)
{
	if (h->buffer[h->cursor] == 0)
	{
		h->cursor--;
		h->buffer[h->cursor] = 0;
		write(1, "\b", 1);
		write(1, " ", 1);
		write(1, "\b", 1);
	}
	else
	{
		swap_buffer_del(h, h->cursor);
	}
}

void	ft_ctrl_left(t_h *h)
{
	while (h->cursor != 0 && h->buffer[h->cursor - 1] == ' ')
	{
		h->cursor--;
		write(1, "\b", 1);
	}
	while (h->cursor != 0 && h->buffer[h->cursor - 1] != ' ')
	{
		h->cursor--;
		write(1, "\b", 1);
	}
}

void	ft_ctrl_right(t_h *h)
{
	while (h->buffer[h->cursor] != 0 && h->buffer[h->cursor] == ' ')
	{
		write(1, &h->buffer[h->cursor], 1);
		h->cursor++;
	}
	while (h->buffer[h->cursor] != 0 && h->buffer[h->cursor] != ' ')
	{
		write(1, &h->buffer[h->cursor], 1);
		h->cursor++;
	}
}

void	ft_ctrl_c(t_h *h)
{
	disablerawmod();
	h->cursor = 0;
	while (h->buffer[h->cursor])
	{
		h->buffer[h->cursor] = 0;
		h->cursor++;
	}
	write(1, "\n", 1);
	h->cursor = 0;
	h->v_cursor = h->v_last_cursor;
	h->error = 1;
}
