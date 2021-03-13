/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forsili <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 22:14:44 by forsili           #+#    #+#             */
/*   Updated: 2021/03/13 22:29:46 by forsili          ###   ########.fr       */
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

char	**trim_apx(char **argv)
{
	int i;
	char *str;

	i = 0;
	while (argv[i])
	{
		if (argv[i][0] == '\'')
		{
			str = argv[i];
			argv[i] = ft_strtrim(argv[i], "\'");
			free(str);
		}
		else if (argv[i][0] == '"')
		{
			str = argv[i];
			argv[i] = ft_strtrim(argv[i], "\"");
			free(str);
		}
		i++;
	}
	return (argv);
}

int		parse_cmd(char **cmd, t_h *h)
{
	char	**arr;
	char	*tmpstr;
	char	**cmdarr;
	int		i;
	int		k;

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
			tmpstr = arr[i];
			arr[i] = ft_strtrim(tmpstr, " \n");
			free(tmpstr);
			//tmpstr = arr[i];
			//arr[i] = ft_strtrim(arr[i], " ");
			//free(tmpstr);
			////printf("(%s)", arr[i]);
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
		free_arr(arr, arr_len(arr));
		k++;
	}
	free_arr(cmdarr, arr_len(cmdarr));
	return (0);
}
