/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forsili <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 16:20:43 by simonegiovo       #+#    #+#             */
/*   Updated: 2021/03/17 15:42:54 by forsili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		is_nflag(char *s)
{
	int i;

	i = 1;
	if (s[0] == '-' && s[1] == 'n')
	{
		while (s[i])
		{
			if (s[i] != 'n')
				return (0);
			i++;
		}
		return (1);
	}
	return (0);
}

void	selective_print(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\\')
			i++;
		write(1, &s[i], 1);
		i++;
	}
}

int		echo_support(char **argv, int nflag)
{
	int i;

	i = 1;
	nflag = 1;
	while (argv[i] && is_nflag(argv[i]))
	{
		i++;
		nflag = i;
	}
	while (argv[i])
	{
		if (i > nflag)
			ft_printf(" ");
		ft_printf("%s", argv[i]);
		i++;
	}
	return (nflag);
}

void	echo_manager(char **argv)
{
	int nflag;

	nflag = 0;
	if (!argv[1])
		ft_printf("");
	else
		nflag = echo_support(argv, nflag);
	if (!nflag)
		ft_printf("\n");
}
