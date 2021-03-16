/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmalori <dmalori@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 19:11:32 by forsili           #+#    #+#             */
/*   Updated: 2021/03/16 12:34:16 by dmalori          ###   ########.fr       */
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

void			disablerawmod(void)
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

static void		ft_while_part2(t_h *h, int temp)
{
	if (temp == 4414235 && h->buffer[h->cursor])
		write(1, &h->buffer[h->cursor++], 1);
	else if (temp == 27)
		ft_exit_readline(h);
	else if (temp == 4283163)
		ft_read_history_up(h);
	else if (temp == 4348699)
		ft_read_history_down(h);
	else if (temp == 4)
		ft_exit_readline(h);
	else if (temp == 993090331)
		;
	else if (temp == 17461)
		ft_ctrl_left(h);
	else if (temp == 17205)
		ft_ctrl_right(h);
	else if (temp == 4741915)
		ft_cmd_home(h);
	else if (temp == 4610843)
		ft_cmd_end(h);
}

void			ft_read_line(t_h *h)
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
			ft_stamp_char(h, temp);
		else if (temp == 127 && h->cursor > 0)
			ft_del_char(h);
		else if (temp == 4479771 && h->cursor > 0)
		{
			h->cursor--;
			write(1, "\b", 1);
		}
		else if (temp == 3)
			return (ft_ctrl_c(h));
		else if (temp == 13)
			return (ft_cmd_invio(h));
		else
			ft_while_part2(h, temp);
	}
}
