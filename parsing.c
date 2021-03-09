/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forsili <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 22:14:44 by forsili           #+#    #+#             */
/*   Updated: 2021/03/09 15:21:11 by forsili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		save_str(int fd, char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(fd, &str[i], 1);
		i++;
	}
	close(fd);
}

int		parse_cmd(char **cmd, t_h *h)
{
	char	**arr;
	char	**cmdarr;
	int		i;
	int		k;
	int		fd;

	fd = open(".history", O_RDWR | O_APPEND);
	save_str(fd, *cmd);
	cmdarr = ft_splitter(*cmd, ';');
	k = 0;
	while (cmdarr[k])
	{
		arr = ft_split_cmd(cmdarr[k], "<>|");
		i = 0;
		while (arr[i])
		{
			arr[i] = ft_strtrim(arr[i], " ");
			arr[i] = ft_strtrim(arr[i], "\n");
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
