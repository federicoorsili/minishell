/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forsili <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 14:06:57 by forsili           #+#    #+#             */
/*   Updated: 2021/03/17 16:32:08 by forsili          ###   ########.fr       */
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
		ft_printf(FRED);
		ft_printf("[%.3d]", h->error);
	}
	else
		ft_printf("%s[000]", FGREEN);
	ft_printf(NONE);
	ft_printf(FCYAN);
	ft_printf(str);
	if (h->sw_dir > 0)
	{
		ft_printf(FPURPLE);
		ft_printf(getcwd(directory, FT_PATH_MAX));
	}
	ft_printf("> %s", NONE);
	h->error = 0;
}
