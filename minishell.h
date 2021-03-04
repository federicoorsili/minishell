/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forsili <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 18:02:55 by forsili           #+#    #+#             */
/*   Updated: 2021/03/04 13:27:13 by forsili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "./libft/libft.h"

# define OPEN_MAX 256
# define BUFFER_SIZE 1
# define FBLACK      "\033[30m"
# define FRED        "\033[31m"
# define FGREEN      "\033[32m"
# define FYELLOW     "\033[33m"
# define FBLUE       "\033[34m"
# define FPURPLE     "\033[35m"
# define D_FGREEN    "\033[6m"
# define FWHITE      "\033[7m"
# define BBLACK      "40m"
# define BRED        "41m"
# define BGREEN      "42m"
# define BYELLOW     "43m"
# define BBLUE       "44m"
# define BPURPLE     "45m"
# define D_BGREEN    "46m"
# define BWHITE      "47m"
# define FCYAN       "\x1b[36m"

# define NONE        "\033[0m"

typedef struct		s_scmd
{
	char			*cmd;
	struct s_scmd	*next;
	struct s_scmd	*prev;
}					t_scmd;

typedef struct		s_cmds
{
	struct s_cmds	*prev;
	struct s_cmds	*next;
	t_scmd			**comand;
}					t_cmds;

int					get_next_line(const int fd, char **line);
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlen(const char *s);
int					is_line(char *str);
int					get_next_line(const int fd, char **line);
t_cmds				*parse_cmd(char **cmd, t_cmds *last);
t_scmd				*newsimplecmd(char *cmd, t_scmd *previous);
t_scmd				*lstlast_smplcmds(t_scmd *lst);
void				add_back_smplcmds(t_scmd **alst, t_scmd *new);
void				lstclear_smplcmds(t_scmd **lst, void (*del)(void *));
t_cmds				*newcomands(t_scmd **cmd, t_cmds *previous);
t_cmds				*lstlast_cmds(t_cmds *lst);
void				add_back_cmds(t_cmds **alst, t_cmds *new);
void				lstclear_cmds(t_cmds **lst, void (*del)(void *));
char				**ft_split_cmd(char *str, char *charset);
char				**ft_splitter(char const *s, char c);
int			        apix_gest(const char *s, char c, int *i, int *sw, char apx);
void		        printercmds(t_cmds *lst);

#endif