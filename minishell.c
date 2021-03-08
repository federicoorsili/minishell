/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forsili <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 18:20:03 by forsili           #+#    #+#             */
/*   Updated: 2021/03/08 16:59:03 by forsili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_putstr(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}

t_cmds	init_cmd(t_cmds last)
{
	last.comand = malloc(1 * sizeof(t_scmd *));
	last.prev = 0;
	last.next = 0;
	last.comand[0] = 0;
	return (last);
}

int		main_loop(t_h *h)
{
	char	*cmd;

	h->path = src_path(*(h->env));
	h->usr = src_usr(*(h->env));
	while (1)
	{
		put_usrname(h->usr);
		get_next_line(0, &cmd);
		parse_cmd(&cmd, h);
		//printercmds(esterna);
		//smister(esterna, h);
		free(cmd);
	}
}

int		main(int argc, char **argv, char **env)
{
	t_h		h;

	h.env = &env;
	main_loop(&h);
	return (0);
}
