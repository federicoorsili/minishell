/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forsili <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 19:11:32 by forsili           #+#    #+#             */
/*   Updated: 2021/03/09 19:31:31 by forsili          ###   ########.fr       */
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

void	ft_read_line(t_h *h)
{
	int temp;
	ft_memset(&h->buffer, 0, 10000);
	enablerawmod();
	while (1)
	{
		temp = 0;
		if (read(STDIN_FILENO, &temp, 4) == -1 && errno != EAGAIN)
			die("read");
		if (temp >= 32 && temp < 127)
		{
			h->buffer[h->cursor++] = temp;
			write(1, &temp, 1);
		}
		else if (temp == 27)
		{
			disablerawmod();
			exit(0);
		}
		else if (temp == 13)
		{
			disablerawmod();
			write(1, "\n", 1);
			h->cursor = 0;
			return ;
		}
		else if (temp != 0)
		{
			//GESTIONE BACK
			printf("%d\r\n", temp);
		}
	}
}
