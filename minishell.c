/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forsili <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 18:20:03 by forsili           #+#    #+#             */
/*   Updated: 2021/03/17 12:10:55 by forsili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_putstr(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}

void		handlesignal(int signal)
{
	if (signal == SIGINT || signal == SIGQUIT)
	{
		g_e.g_signalaction = 1;
	}
}

static char	*ft_read_test(int fd, t_h *h)
{
	char *str;
	int	res;

	str = NULL;
	res = ft_get_next_line(fd, &str);
	if (res != 1)
		free_exit(h, 0);
	return (str);
}

static int	main_loop(t_h *h, int argc, char **argv)
{
	char	*cmd;
	int		fd;

	ft_start();
	h->sw_dir = 1;
	if (argc == 2)
		fd = open(argv[1], O_RDONLY);
	while (1)
	{
		h->path = src_path(h->our_env);
		if (signal(SIGINT, handlesignal) == SIG_ERR)
			write(2, "Error catching signal C \r\n", 26);
		if (signal(SIGQUIT, handlesignal) == SIG_ERR)
			write(2, "Error catching signal C \r\n", 26);
		if (g_e.g_signalaction == 1)
			g_e.g_signalaction = 0;
		src_usr(h->our_env, h);
		put_usrname(h->usr, h);
		if (argc == 1)
		{
			ft_read_line(h);
			cmd = ft_strdup(h->buffer);
		}
		else
			cmd = ft_read_test(fd, h);
		parse_cmd(&cmd, h);
		free(cmd);
		free_arr(h->path, arr_len(h->path));
	}
}

int			main(int argc, char **argv, char **env)
{
	t_h				h;
	char			*tmp;

	if (argc > 2)
		exit(-1);
	g_e.g_signalaction = 0;
	ft_memset(&h, 0, sizeof(t_h));
	crt_env(env, &h);
	h.error = 0;
	h.cursor = 0;
	h.v_cursor = 0;
	tmp = malloc(FT_PATH_MAX + 7);
	tmp = getcwd(tmp, FT_PATH_MAX);
	h.history_path = ft_strjoin(tmp, "/.history");
	free(tmp);
	h.tmp_env = ft_calloc(ENV_SIZE, sizeof(char *));
	ft_convert_history(&h);
	main_loop(&h, argc, argv);
	return (0);
}
