/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forsili <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 18:02:55 by forsili           #+#    #+#             */
/*   Updated: 2021/03/01 18:46:22 by forsili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <stdio.h>
# include <unistd.h>



typedef struct      s_scmd
{
    char            *cmd;
    struct s_scmd   *next;
    struct s_scmd   *prev;
}                   t_scmd;

typedef struct      s_cmds
{
    struct s_cmds 	*prev;
	struct s_cmds	*next;
	t_scmd 			*comand;
}                   t_cmds;



#endif