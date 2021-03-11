/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ourturn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgiovo <sgiovo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 12:55:06 by sgiovo            #+#    #+#             */
/*   Updated: 2021/03/11 14:38:12 by sgiovo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		cd(char **argv, t_h *h)
{
	if (!argv[1])
	{
		argv[1] = ft_strdup("/Users/");
		argv[1] = ft_strjoin(argv[1], h->usr);
	}
	errno = 0;
	chdir(argv[1]);
	return (errno);
}

int		ft_get_pwd(t_h *h)
{
	char	path[4096];
	int		error;

	errno = 0;
	getcwd(path, FT_PATH_MAX);
	printf("%s\n", path, errno);
	return (errno);
}

int		ourturn_father(t_h *h, int i, char *cmd, char **argv)
{
	if ((ft_strncmp(argv[0], "cd", ft_strlen(argv[0])) == 0) && ft_strlen(argv[0]) == ft_strlen("cd"))
	{
		h->error = cd(argv, h);
		return (1);
	}
	if ((ft_strncmp(argv[0], "pwd", ft_strlen(argv[0])) == 0) && ft_strlen(argv[0]) == ft_strlen("pwd"))
	{
		h->error = ft_get_pwd(h);
		return (1);
	}
	return (0);
}
