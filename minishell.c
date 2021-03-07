/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forsili <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 18:20:03 by forsili           #+#    #+#             */
/*   Updated: 2021/03/07 11:42:46 by forsili          ###   ########.fr       */
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

int		main_loop(t_cmds *esterna, t_h *h)
{
	char	*cmd;
	char	*pat;
	t_cmds	*tmp;

	h->path = src_path(*(h->env));
	h->usr = src_usr(*(h->env));
	if (!(pat = malloc(FT_PATH_MAX * sizeof(char))))
		return (0);
	while (1)
	{
		pat = getcwd(pat,FT_PATH_MAX );
		put_usrname(h);
		ft_putstr(pat);
		ft_putstr("> "NONE);
		get_next_line(0, &cmd);
		esterna = parse_cmd(&cmd, &*esterna);
		//printercmds(esterna);
		smister(esterna, h);
		free(cmd);
	}
}

int		main(int argc, char **argv, char **env)
{
	t_cmds  esterna;
	t_h		h;

	h.env =  &env;
	esterna = init_cmd(esterna);
	main_loop(&esterna, &h);
	return (0);
}
