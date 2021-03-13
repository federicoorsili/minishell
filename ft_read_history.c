#include "minishell.h"

void ft_convert_history(t_h *h)
{
	int fd;
	char *line;
	int i;

	fd = open(".history", O_RDWR | O_APPEND | O_CREAT, 0755);
	h->history = malloc(5000 * sizeof(char *));
	while(ft_get_next_line(fd, &line))
	{
		h->history[h->v_cursor] = line;
		h->v_cursor++;
	}
	free(line);
	h->v_last_cursor = h->v_cursor;
	close(fd);
}

void ft_read_history_up(t_h *h)
{
	int fd;
	int i;

	i = 0;
	if (h->v_cursor > 0)
	{
		free(h->history[h->v_cursor]);
		h->history[h->v_cursor] = ft_strdup(h->buffer);
		while(h->buffer[h->cursor])
		{
			write(1, " ", 1);
			h->cursor++;
		}
		while (h->cursor > 0)
		{
			h->cursor--;
			h->buffer[h->cursor] = 0;
			write(1, "\b", 1);
			write(1, " ", 1);
			write(1, "\b", 1);
		}
		h->v_cursor--;
		while (h->history[h->v_cursor][i])
		{
			h->buffer[i] = h->history[h->v_cursor][i];
			i++;
		}
		write(1, h->history[h->v_cursor], ft_strlen(h->history[h->v_cursor]));
		h->cursor = ft_strlen(h->history[h->v_cursor]);
	}
	//ft_printf("\n\rC%d - LC%d ", h->v_cursor, h->v_last_cursor);
}

void ft_read_history_down(t_h *h)
{
	int fd;
	int i;

	i = 0;
	if (h->v_cursor <= h->v_last_cursor - 1)
	{
		free(h->history[h->v_cursor]);
		h->history[h->v_cursor] = ft_strdup(h->buffer);
		while(h->buffer[h->cursor])
		{
			write(1, " ", 1);
			h->cursor++;
		}
		while (h->cursor > 0)
		{
			h->cursor--;
			h->buffer[h->cursor] = 0;
			write(1, "\b", 1);
			write(1, " ", 1);
			write(1, "\b", 1);
		}
		h->v_cursor++;
		while (h->history[h->v_cursor][i])
		{
			h->buffer[i] = h->history[h->v_cursor][i];
			i++;
		}
		write(1, h->history[h->v_cursor], ft_strlen(h->history[h->v_cursor]));
		h->cursor = ft_strlen(h->history[h->v_cursor]);
	}
	//ft_printf("\r\nC%d - LC%d ", h->v_cursor, h->v_last_cursor);
}