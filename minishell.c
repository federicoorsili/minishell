/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forsili <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 18:20:03 by forsili           #+#    #+#             */
/*   Updated: 2021/03/01 18:47:15 by forsili          ###   ########.fr       */
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
	char c;
	char buff;

	c = 0;
	while (1)
	{
		ft_putstr("sgiovo>");
		while (c != '\n')
		{
			read(0, &buff, 1);
			c = buff;
		}
		c = 0;
	}
}

int		main(void)
{
	t_cmds	last;

	main_loop(&last);
	return (0);
}
