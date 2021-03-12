/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forsili <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 22:14:44 by forsili           #+#    #+#             */
/*   Updated: 2021/03/12 12:22:25 by forsili          ###   ########.fr       */
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
	h->history[h->v_last_cursor] = ft_strdup(str);
	h->v_cursor = ++h->v_last_cursor;
}

char	*trim_apx(char *str)
{
	int sw;

	sw = 0;
	if (str[0] == '\'')
		str = ft_strtrim(str, "\'");
	else if (str[0] == '"')
		str = ft_strtrim(str, "\"");
	return (str);
}

int		parse_cmd(char **cmd, t_h *h)
{
	char	**arr;
	char	**cmdarr;
	int		i;
	int		k;
	int		fd;

	fd = open(h->history_path, O_RDWR | O_APPEND | O_CREAT, 0755);
	save_str(h, *cmd);
	cmdarr = ft_splitter(*cmd, ';');
	k = 0;
	while (cmdarr[k])
	{
		arr = ft_split_cmd(cmdarr[k], "<>|");
		i = 0;
		arr = expand_var(h, arr);
		while (arr[i])
		{
			arr[i] = ft_strtrim(arr[i], " ");
			arr[i] = ft_strtrim(arr[i], "\n");
			arr[i] = trim_apx(arr[i]);
			//printf("(%s)", arr[i]);
			i++;
		}
		//printf("\n");
		i = 0;
		while (arr[i])
		{
			i = gestor_cmd(arr, i, h);
			if (arr[i])
				i++;
		}
		k++;
	}
	free(cmdarr);
	return (0);
}
