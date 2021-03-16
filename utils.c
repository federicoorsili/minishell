/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmalori <dmalori@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 14:06:57 by forsili           #+#    #+#             */
/*   Updated: 2021/03/16 14:08:26 by dmalori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**free_arr(char **arr, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		free(arr[i]);
		i++;
	}
	free(arr[i]);
	free(arr);
	return (arr);
}

void	src_usr(char **tmp, t_h *h)
{
	int		i;
	char	**out;

	i = 0;
	free(h->usr);
	while (tmp[i])
	{
		if (!ft_strncmp(tmp[i], "LOGNAME=", 8))
			break ;
		i++;
	}
	out = ft_split(tmp[i], '=');
	h->usr = ft_strdup(out[1]);
	free_arr(out, arr_len(out));
}

void	put_usrname(char *str, t_h *h)
{
	char	directory[FT_PATH_MAX];

	if (h->error != 0)
	{
		ft_putstr(FRED);
		ft_printf("[%.3d]", h->error);
	}
	else
		ft_putstr(FGREEN"[000]");
	ft_putstr(NONE);
	ft_putstr(FCYAN);
	ft_putstr(str);
	if (h->sw_dir > 0)
	{
		ft_putstr(FPURPLE);
		ft_putstr(getcwd(directory, FT_PATH_MAX));
	}
	ft_putstr("> "NONE);
	h->error = 0;
}
