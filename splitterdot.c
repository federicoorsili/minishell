/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splitterdot.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmalori <dmalori@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 16:49:40 by forsili           #+#    #+#             */
/*   Updated: 2021/03/14 11:31:20 by dmalori          ###   ########.fr       */
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

char			**ft_splitter(char *str, char *c)
{
	//DEBUG
	//printf("%sENTER SPLITTER '%s'%s\n", FGREEN, c, NONE);
	// STOP DEBUG

	t_var_splitter var;

	ft_init_var(&var);
	while (str[var.i])
	{
		if (str[var.i] == '\\' && var.type_apice != '\'')
		{
			if (str[var.i + 1])
				var.i += 2;
			else
			{
				var.bs = 1;
				break;
			}
		}
		else if ((str[var.i] == '\'' || str[var.i] == '\"') && var.type_apice == -1)
		{
			var.type_apice = str[var.i];
			var.i++;
		}
		else if (str[var.i] == var.type_apice)
		{
			var.type_apice = -1;
			var.i++;
		}
		else if (ft_iscontain(str[var.i], c) && var.type_apice == -1)
		{
			var.stop[var.size] = var.i++;
			while (str[var.i] == ' ')
				var.i++;
			if (str[var.i])
				var.start[++var.size] = var.i;
		}
		else
			var.i++;
	}
	//var.stop[var.size] = var.i;
	if (var.type_apice != -1 || var.bs != -1)
		printf("ERRORE\n");
	if (!(var.matrix = malloc((var.size + 2) * sizeof(char *))))
		return (NULL);
	var.i = 0;
	while (var.i <= var.size)
	{
		var.matrix[var.i] = ft_substr(str, var.start[var.i],(var.stop[var.i] - var.start[var.i]));
		var.i++;
	}
	var.matrix[var.i] = NULL;
	
	//DEBUG
	for (int i = 0; var.matrix[i]; i++)
	//	printf("%s%d = %.2d/%.2d || _%s_%s\n", FYELLOW,i, var.start[i], var.stop[i], var.matrix[i], NONE);
	//printf("%sEXIT SPLITTER%s\n", FRED, NONE);
	//STOP DEBUG

	return (var.matrix);
}
