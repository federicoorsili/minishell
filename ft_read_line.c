/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forsili <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 19:11:32 by forsili           #+#    #+#             */
/*   Updated: 2021/03/16 11:14:34 by forsili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		die(const char *s)
{
	write(STDOUT_FILENO, "\x1b[2J", 4);
	write(STDOUT_FILENO, "\x1b[H", 3);
	perror(s);
	exit(1);
}

static void		disablerawmod(void)
{
	if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &e.orig_termios) == -1)
		die("tcsetattr");
}

static void		enablerawmod(void)
{
	struct termios raw;

	if (tcgetattr(STDIN_FILENO, &e.orig_termios) == -1)
		die("tcgetattr");
	atexit(disablerawmod);
	raw = e.orig_termios;
	raw.c_iflag &= ~(BRKINT | ICRNL | INPCK | ISTRIP | IXON);
	raw.c_oflag &= ~(OPOST);
	raw.c_cflag |= (CS8);
	raw.c_lflag &= ~(ECHO | ICANON | IEXTEN | ISIG);
	raw.c_cc[VMIN] = 0;
	raw.c_cc[VTIME] = 1;
	if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw) == -1)
		die("tcsetattr");
}

static void	swap_buffer(t_h *h, int c, int i)
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

static void	swap_buffer_del(t_h *h, int i)
{
	while (h->buffer[i])
	{
		h->buffer[i - 1] = h->buffer[i];
		//write(1, &h->buffer[i], 1);
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

void	ft_read_line(t_h *h)
{
	int temp;

	ft_memset(&h->buffer, 0, MAX_BUFFER);
	enablerawmod();
	while (1)
	{
		temp = 0;
		if (read(STDIN_FILENO, &temp, 4) == -1 && errno != EAGAIN)
			die("read");
		if (temp >= 32 && temp < 127)
		{
			if (h->buffer[h->cursor])
				swap_buffer(h, temp, h->cursor);
			else
			{
				h->buffer[h->cursor++] = temp;
				write(1, &temp, 1);
			}
		}
		else if (temp == 127 && h->cursor > 0)
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
		else if (temp == 4479771 && h->cursor > 0)
		{
			h->cursor--;
			write(1, "\b", 1);
		}
		else if (temp == 4414235 && h->buffer[h->cursor])
		{
			write(1, &h->buffer[h->cursor], 1);
			h->cursor++;
		}
		else if (temp == 27)
		{
			disablerawmod();
			write(1, "\n", 1);
			free_exit(h, 0);
		}
		else if (temp == 13)
		{
			disablerawmod();
			while (h->buffer[h->cursor])
				h->cursor++;
			write(1, "\n", 1);
			h->cursor = 0;
			h->v_cursor = h->v_last_cursor;
			return ;
		}
		//UP
		else if (temp == 4283163)
		{
			ft_read_history_up(h);
		}
		///DOWN
		else if (temp == 4348699)
		{
			ft_read_history_down(h);	
		}
		//CTR-C
		else if (temp == 3)
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
			return ;
		}
		//CTR-D
		else if (temp == 4)
		{
			disablerawmod();
			write(1, "\n", 1);
			free_exit(h, 0);
		}
		//CTR-LEFT && CTRL-RIGHT
		else if (temp == 993090331)
		{
			//CLEAN CTRL
		}
		//..LEFT
		else if(temp == 17461)
		{
			while (h->cursor != 0 && h->buffer[h->cursor - 1] == ' ')
			{
				h->cursor--;
				write(1, "\b", 1);
			}
			while(h->cursor != 0 && h->buffer[h->cursor - 1] != ' ')
			{
				h->cursor--;
				write(1, "\b", 1);
			}
		}
		//..RIGHT
		else if (temp == 17205)
		{
			while (h->buffer[h->cursor] != 0 && h->buffer[h->cursor] == ' ')
			{
				write(1, &h->buffer[h->cursor], 1);
				h->cursor++;
			}
			while(h->buffer[h->cursor] != 0 && h->buffer[h->cursor] != ' ')
			{
				write(1, &h->buffer[h->cursor], 1);
				h->cursor++;
			}
		}
		//HOME
		else if (temp == 4741915)
		{
			while(h->cursor != 0)
			{
				h->cursor--;
				write(1, "\b", 1);
			}
		}
		//FINE
		else if (temp == 4610843)
		{
			while (h->buffer[h->cursor] != 0)
			{
				write(1, &h->buffer[h->cursor], 1);
				h->cursor++;
			}
		}
		//DEBUG
		else if (temp != 0)
		{
			printf("%d\r\n", temp);
		}
	}
}
