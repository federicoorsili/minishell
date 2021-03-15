/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forsili <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 18:02:55 by forsili           #+#    #+#             */
/*   Updated: 2021/03/15 14:09:41 by forsili          ###   ########.fr       */
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
# include <ctype.h>
# include <errno.h>
# include <termios.h>
# include <signal.h>
# include <sys/stat.h>
# include "./libft/libft.h"

# define FBLACK      "\033[30m"
# define FRED        "\033[31m"
# define FGREEN      "\033[32m"
# define FYELLOW     "\033[33m"
# define FBLUE       "\033[34m"
# define FPURPLE     "\033[35m"
# define D_FGREEN    "\033[6m"
# define FWHITE      "\033[7m"
# define BBLACK      "\e[40m"
# define BRED        "\e[41m"
# define BGREEN      "\e[42m"
# define BYELLOW     "\e[43m"
# define BBLUE       "\e[44m"
# define BPURPLE     "\e[45m"
# define D_BGREEN    "\e[46m"
# define BWHITE      "\e[47m"
# define FCYAN       "\x1b[36m"
# define NONE        "\033[0m"
# define FT_PATH_MAX 4096
# define MAX_CMDS 100
# define MAX_BUFFER 10000
# define MAX_FRED 1000000
# define MAX_FD 1200
# define ENV_SIZE 500

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
	char			**our_env;
	char			**tmp_env;
	char			**path;
	char			**history;
	char			*history_path;
	char			*usr;
	int				fdhistory;
	int				pipe[MAX_FD][2];
	int				npipes;
	int				nredir;
	int				ndoubler;
	int				revred;
	int				fdred[MAX_FD];
	char			bufred[MAX_FRED];
	int				error;
	int				cursor;
	char			buffer[MAX_BUFFER];
	int				v_cursor;
	int				v_last_cursor;
	int				next_redirection;
}					t_h;

struct	s_editorconfig {
	struct termios	orig_termios;
};

struct s_editorconfig		e;

int					arr_len(char **arr);
void				ft_putstr(char *s);
int					get_next_line(const int fd, char **line);
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlen(const char *s);
int					is_line(char *str);
int					get_next_line(const int fd, char **line);
int					parse_cmd(char **cmd, t_h *h);
char				**ft_split_cmd(char *str, char *charset);
char				**ft_splitter(char *str, char *c);
int					apix_gest(char *s, char c, int *i, int *sw, char *apx);
void				printercmds(t_cmds *lst);
int					lstcounter_smplcmds(t_scmd *lst);
int					smister(t_cmds *esterna, t_h *h);
char				**src_path(char **tmp);
int					ft_syscall(char **s, t_h *h, int k);
char				**free_arr(char **arr, int len);
void				src_usr(char **tmp, t_h *h);
void				put_usrname(char *str, t_h *h);
void				reset_pipe(t_h *h);
int					gestor_cmd(char **tmpcmd, int k, t_h *h);
void				open_pipes(t_h *h, int k);
void				close_pipeson(t_h *h, int k);
void				close_allfather(t_h *h, int k);
void				exec_cmd(t_h *h, int i, char *cmd, char **argv);
void				count_pipes(t_h *h, int k, char **tmpcmd);
void				count_redirection(t_h *h, int k, char **tmpcmd);
void				open_redirection(t_h *h, int k, char **tmpcmd);
int					close_redirection(t_h *h, int k, char **tmpcmd);
void				write_file(t_h *h, int k);
void				read_file(t_h *h, int k, int mod);
int					main_loop(t_h *h);
void				count_double_redir_pre(t_h *h, char **tmpcmd);
void				count_double_redir(t_h *h, int k, char **tmpcmd);
void				open_double_redir(t_h *h, int k, char **tmpcmd);
int					close_doubel_redir(t_h *h, int k, char **tmpcmd);
int					ourturn_father(t_h *h, char *cmd, char **argv);
char				*count_revredir(t_h *h, int k, char **tmpcmd);
void				ft_read_line(t_h *h);
void				ft_read_history_up(t_h *h);
void				ft_read_history_down(t_h *h);
void				ft_convert_history(t_h *h);
void				crt_env(char **env, t_h *h);
int					ft_export(t_h *h);
int					declarated(char **env, char *argv);
char				*src_home(char **tmp);
char				**expand_var(t_h *h, char **argv);
char				**trim_apx(char **argv);
void				free_exit(t_h *h, int code);
int					ft_single_export(t_h *h, char **argv);
char				**ft_array_swap(char ***env, char **argv, int i);
int					ft_unset_manager(t_h *h, char **argv);

#endif
