/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forsili <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 18:02:55 by forsili           #+#    #+#             */
/*   Updated: 2021/03/09 12:17:31 by forsili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>
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
# define BRED        "\e[41m"
# define BGREEN      "42m"
# define BYELLOW     "43m"
# define BBLUE       "44m"
# define BPURPLE     "45m"
# define D_BGREEN    "46m"
# define BWHITE      "47m"
# define FCYAN       "\x1b[36m"
# define NONE        "\033[0m"
# define FT_PATH_MAX 4096
#define MAX_CMDS 100

typedef struct	s_var_splitter
{
	int		bs;
	int		i;
	char	type_apice;
	char	**matrix;
	int		size;
	int		start[MAX_CMDS];
	int		stop[MAX_CMDS];
}				t_var_splitter;

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

typedef	struct		s_h
{
	int				fdhistory;
	char			***env;
	char			**out;
	char			**path;
	char			*usr;
	int				pipe[1200][2];
	int				npipes;
	int				nredir;
	int				ndoubler;
	char			revred[1000][1000];
	int				fdred[1200];
	char			bufred[1000000];
}					t_h;

int					arr_len(char **arr);
void				ft_putstr(char *s);
int					get_next_line(const int fd, char **line);
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlen(const char *s);
int					is_line(char *str);
int					get_next_line(const int fd, char **line);
int					parse_cmd(char **cmd, t_h *h);
char				**ft_split_cmd(char *str, char *charset);
char				**ft_splitter(char *str, char c);
int					apix_gest(char *s, char c, int *i, int *sw, char *apx);
void				printercmds(t_cmds *lst);
int					lstcounter_smplcmds(t_scmd *lst);
int					smister(t_cmds *esterna, t_h *h);
char				**src_path(char **tmp);
int					ft_syscall(char **s, t_h *h, int k);
char				**free_arr(char **arr);
char				*src_usr(char **tmp);
void				put_usrname(char *str);
void				reset_pipe(t_h *h);
void				gestor_cmd(char **tmpcmd, int k, t_h *h);
void				open_pipes(t_h *h, int k);
void				close_pipeson(t_h *h, int k);
void				close_allfather(t_h *h, int k);
void				exec_cmd(t_h *h, int i, char *cmd, char **argv);
void				count_pipes(t_h *h, int k, char **tmpcmd);
void				count_redirection(t_h *h, int k, char **tmpcmd);
void				open_redirection(t_h *h, int k);
int					close_redirection(t_h *h, int k, char **tmpcmd);
void				write_file(t_h *h, int k, char *buf);
void				read_file(t_h *h, int k);
int					main_loop(t_h *h);
void				count_double_redir(t_h *h, int k, char **tmpcmd);
void				open_double_redir(t_h *h, int k, char **tmpcmd);
int					close_doubel_redir(t_h *h, int k, char **tmpcmd);
void				count_revredir(t_h *h, int k, char **tmpcmd);

#endif