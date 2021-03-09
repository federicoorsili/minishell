/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ourturn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgiovo <sgiovo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 12:55:06 by sgiovo            #+#    #+#             */
/*   Updated: 2021/03/09 15:10:27 by sgiovo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	cd(char *path, t_h *h)
{
	int n;
	if (!path)
	{
		path = ft_strdup("/Users/");
		path = ft_strjoin(path, h->usr);
	}
	n = chdir(path);
	printf("ciao %d\n", n);
}

int	ourturn_father(t_h *h, int i, char *cmd, char **argv)
{
	int error;
	if ((ft_strncmp(argv[0], "cd", ft_strlen(argv[0])) == 0))
	{
		//printf("%s\n", argv[1]);
		//printf("RISULTATO: %d\nq", );
		error = cd(argv[1], h);
		return (1);
	}     
	return (0);
}

