/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_buffer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmalori <dmalori@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 11:51:12 by dmalori           #+#    #+#             */
/*   Updated: 2021/03/16 11:58:22 by dmalori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	swap_buffer(t_h *h, int c, int i)
{
	int temp;

	temp = h->buffer[i];
	h->buffer[i] = c;
	write(1, &c, 1);
	if (h->buffer[i + 1])
		swap_buffer(h, temp, i + 1);
	if (h->buffer[i + 1] == 0)
	{
		write(1, &temp, 1);
		h->buffer[i + 1] = temp;
		while (i >= h->cursor)
		{
			write(1, "\b", 1);
			i--;
		}
		h->cursor++;
	}
}

void	swap_buffer_del(t_h *h, int i)
{
	while (h->buffer[i])
	{
		h->buffer[i - 1] = h->buffer[i];
		i++;
	}
	h->buffer[i - 1] = 0;
	h->cursor--;
	i = h->cursor;
	write(1, "\b", 1);
	while (h->buffer[i])
	{
		write(1, &h->buffer[i], 1);
		i++;
	}
	h->buffer[i] = 0;
	write(1, " ", 1);
	while (i-- != h->cursor)
		write(1, "\b", 1);
	write(1, "\b", 1);
}
