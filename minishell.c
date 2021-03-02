/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forsili <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 18:20:03 by forsili           #+#    #+#             */
/*   Updated: 2021/03/02 15:22:58 by forsili          ###   ########.fr       */
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

int		main_loop(t_cmds *last)
{
	char	c;
	char	*cmd;

	c = 0;
	while (1)
	{
		ft_putstr(FCYAN"sgiovo> "NONE);
		get_next_line(0, &cmd);
		last = parse_cmd(&cmd, &*last);
		free(cmd);
		ft_putstr("\n");
		c = 0;
	}
}

int		main(void)
{
	t_cmds	last;

	last.prev = 0;
	main_loop(&last);
	return (0);
}
