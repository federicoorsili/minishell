/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splitterdot.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forsili <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 16:49:40 by forsili           #+#    #+#             */
/*   Updated: 2021/03/09 12:22:49 by forsili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		ft_init_var(t_var_splitter *var)
{
	var->bs = -1;
	var->i = 0;
	var->type_apice = -1;
	var->matrix = NULL;
	var->size = 0;
	ft_memset(var->start, -1, MAX_CMDS);
	ft_memset(var->stop, -1, MAX_CMDS);
	var->start[0] = 0;
}

static void		ft_loop_bs(char *str, t_var_splitter *var)
{
	while (str[var->i] == '\\' && var->type_apice != '\'')
	{
		var->bs *= -1;
		var->i++;
		ft_loop_bs(str, var);
		return;
	}
	if (var->bs == 1 && str[var->i])
	{
		var->bs = -1;
		var->i++;
		ft_loop_bs(str, var);
		return;
	}
}

static void		ft_loop_apici(char *str, t_var_splitter *var)
{
	if (var->type_apice == -1 && (str[var->i] == '\'' || str[var->i] == '\"'))
	{
		var->type_apice = str[var->i];
		var->i++;
		ft_loop_apici(str, var);
		return;
	}
	if (var->type_apice == '\"')
		ft_loop_bs(str, var);
	if (var->type_apice != -1 && str[var->i] == var->type_apice)
	{
		var->type_apice = -1;
		var->i++;
		ft_loop_apici(str, var);
		return;
	}
}

static int		ft_control_split(char *str, char c, t_var_splitter *var)
{
	if (str[var->i] == c && var->type_apice == -1)
	{
		if (var->i == 0)
			return (1);
		var->stop[var->size] = var->i;
		var->i++;
		if (str[var->i] == c)
			return (1);
		if (str[var->i] != 0)
		{
			var->size++;
			var->start[var->size] = var->i;
		}
	}
	return (0);
}

char			**ft_splitter(char *str, char c)
{
	t_var_splitter var;

	ft_init_var(&var);
	while (str[var.i])
	{
		ft_loop_bs(str, &var);
		if (ft_control_split(str, c, &var))
			printf("ERRORE 1\n");
		ft_loop_apici(str, &var);
		var.i++;
	}
	if (var.size == 0 && var.stop[0] == -1)
		var.stop[0] = var.i;
	if (var.type_apice != -1 || var.bs != -1)
		printf("ERRORE 2\n");
	if (!(var.matrix = malloc((var.size + 2) * sizeof(char *))))
		return (NULL);
	var.i = -1;
	while (var.i++ < var.size)
		var.matrix[var.i] = ft_substr(str, var.start[var.i],
			(var.stop[var.i] - var.start[var.i]));
	var.matrix[var.i] = 0;
	return (var.matrix);
}