/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forsili <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 18:20:03 by forsili           #+#    #+#             */
/*   Updated: 2021/03/03 23:19:09 by forsili          ###   ########.fr       */
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
	last.prev = 0;
	last.next = 0;
	last.comand[0] = 0;
	return (last);
}

int		main_loop(t_cmds *esterna)
{
	char	c;
	char	*cmd;
	t_cmds	*tmp;

	c = 0;
	while (1)
	{
		ft_putstr(FCYAN"sgiovo> "NONE);
		get_next_line(0, &cmd);
		esterna = parse_cmd(&cmd, &*esterna);
		printercmds(esterna);
		free(cmd);
		ft_putstr("\n");
		c = 0;
	}
}

int		main(void)
{
	t_cmds  esterna;
	esterna = init_cmd(esterna);
	main_loop(&esterna);
	return (0);
}
