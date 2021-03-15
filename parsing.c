/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simonegiovo <simonegiovo@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 22:14:44 by forsili           #+#    #+#             */
/*   Updated: 2021/03/15 15:38:59 by simonegiovo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	save_str(t_h *h, char *str)
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

char	**trim_apx(char **argv)
{
	int i;
	char *str;

	i = 0;
	while (argv[i])
	{
		if (argv[i][0] == '\'')
			argv[i] = ft_strtrim(&argv[i], "\'", 1);
		else if (argv[i][0] == '"')
			argv[i] = ft_strtrim(&argv[i], "\"", 1);
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
	cmdarr = ft_splitter(*cmd, ";");
	k = 0;
	while (cmdarr[k])
	{
		arr = ft_split_cmd(cmdarr[k], "<>|");
		i = 0;
		arr = expand_var(h, arr);
		while (arr[i])
		{
			arr[i] = ft_strtrim(&arr[i], " \n", 1);
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
		ft_memset(h->bufred, 0, MAX_FRED);
	}
	free_arr(cmdarr, arr_len(cmdarr));
	return (0);
}
