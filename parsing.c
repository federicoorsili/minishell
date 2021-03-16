/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmalori <dmalori@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 22:14:44 by forsili           #+#    #+#             */
/*   Updated: 2021/03/16 17:07:06 by dmalori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		save_str(t_h *h, char *str)
{
	int fd;
	int i;

	if (str[0] == 0)
		return ;
	i = 0;
	fd = open(h->history_path, O_RDWR | O_APPEND | O_CREAT, 0755);
	while (str[i])
	{
		write(fd, &str[i], 1);
		i++;
	}
	write(fd, "\n", 1);
	close(fd);
	free(h->history[h->v_last_cursor]);
	h->history[h->v_last_cursor] = ft_strdup(str);
	h->v_cursor = ++h->v_last_cursor;
}

static void	ft_loop_apix(char *str, int last_apix, int *j, char buff[1000])
{
	int i;

	i = 1;
	while (str[i])
	{
		if (str[i] == last_apix)
		{
			i++;
			last_apix = -1;
		}
		else if (last_apix == '\'')
			buff[j[0]++] = str[i++];
		else if (str[i] == '\\')
		{
			i++;
			buff[j[0]++] = str[i++];
		}
		else if (str[i] == '\'' || str[i] == '"')
			last_apix = str[i++];
		else
			buff[j[0]++] = str[i++];
	}
}

char		*ft_trim_apx(char *str)
{
	char	*out;
	int		i;
	char	buff[1000];
	int		last_apix;
	int		j;

	i = 0;
	j = 0;
	last_apix = str[i++];
	if (ft_strlen(str) == 2)
	{
		free(str);
		return (ft_strdup(""));
	}
	ft_loop_apix(str, last_apix, &j, buff);
	buff[j] = 0;
	out = ft_strdup(buff);
	free(str);
	return (out);
}

char		**trim_apx(char **argv, t_h *h)
{
	int i;

	i = 0;
	ft_memset(h->apix_str, 0, APX_MAX);
	while (argv[i])
	{
		argv[i] = ft_strtrim(&argv[i], " ", 1);
		if (argv[i][0] == '\'' || argv[i][0] == '"')
		{
			if (argv[i][0] == '\'')
				h->apix_str[i] = 1;
			argv[i] = ft_trim_apx(argv[i]);
		}
		i++;
	}
	return (argv);
}

int			parse_cmd(char **cmd, t_h *h)
{
	char	**arr;
	char	**cmdarr;
	int		i;
	int		k;

	save_str(h, *cmd);
	cmdarr = ft_splitter(*cmd, ";", 0);
	if (cmdarr == NULL)
		return (0);
	k = -1;
	while (cmdarr[++k])
	{
		arr = ft_splitter(cmdarr[k], "<>|", 1);
		i = -1;
		arr = expand_var(h, arr);
		while (arr[++i])
			arr[i] = ft_strtrim(&arr[i], " \n", 1);
		i = -1;
		while (arr[++i])
			gestor_cmd(arr, i, h);
		free_arr(arr, arr_len(arr));
		ft_memset(h->bufred, 0, MAX_FRED);
	}
	free_arr(cmdarr, arr_len(cmdarr));
	return (0);
}
