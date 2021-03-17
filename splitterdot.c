/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splitterdot.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forsili <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 16:49:40 by forsili           #+#    #+#             */
/*   Updated: 2021/03/17 16:11:27 by forsili          ###   ########.fr       */
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

static void		ft_add_char_split(t_var_splitter *var, int c, char *str)
{
	var->stop[var->size] = var->i;
	var->start[++var->size] = var->i++;
	while (str[var->i] == c)
		var->i++;
	var->stop[var->size] = var->i;
}

static int		ft_splitter_loop_bis(char *str, char *c, t_var_splitter *var)
{
	if (str[var->i] == var->type_apice)
	{
		var->type_apice = -1;
		var->i++;
	}
	else if (ft_iscontain(str[var->i], c) && var->type_apice == -1)
	{
		if (var->mod)
			ft_add_char_split(var, str[var->i], str);
		else
			var->stop[var->size] = var->i++;
		while (str[var->i] == ' ')
			var->i++;
		if (c[0] == ';' && str[var->i] == ';')
			return (-1);
		if (str[var->i])
			var->start[++var->size] = var->i;
	}
	else
		var->i++;
	return (0);
}

static void		ft_splitter_loop(char *str, char *c,
	t_var_splitter *var, t_h *h)
{
	while (str[var->i])
	{
		if (str[var->i] == '\\' && var->type_apice != '\'')
		{
			if (str[var->i + 1])
				var->i += 2;
			else
			{
				var->bs = 1;
				break ;
			}
		}
		else if ((str[var->i] == '\'' || str[var->i] == '\"') &&
			var->type_apice == -1)
		{
			var->type_apice = str[var->i];
			var->i++;
		}
		else if (ft_splitter_loop_bis(str, c, var) == -1)
		{
			var->bs = 1;
			h->error = 258;
			return ;
		}
	}
}

char			**ft_splitter(char *str, char *c, int mod, t_h *h)
{
	t_var_splitter var;

	ft_init_var(&var);
	var.mod = mod;
	if (str[0] == ';')
	{
		printf(FYELLOW"Warning: format error\n"NONE);
		h->error = 258;
		return (NULL);
	}
	ft_splitter_loop(str, c, &var, h);
	if (var.type_apice != -1 || var.bs != -1)
	{
		printf(FYELLOW"Warning: format error\n"NONE);
		return (NULL);
	}
	if (!(var.matrix = malloc((var.size + 2) * sizeof(char *))))
		return (NULL);
	var.i = -1;
	while (++var.i <= var.size)
		var.matrix[var.i] = ft_substr(str, var.start[var.i],
			(var.stop[var.i] - var.start[var.i]));
	var.matrix[var.i] = NULL;
	return (var.matrix);
}
