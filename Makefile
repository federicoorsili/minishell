NAME	=	minishell
CC		=	gcc -pedantic -g
FT_DIR	=	libft
FT_LNK	=	-L ${FT_DIR} -lft
#CFLAGS	=	-Wall -Wextra -Werror	
RM		=	rm -f
SRCS	=	minishell.c \
			parsing.c \
			splitcmd.c \
			splitcmd2.c \
			splitterdot.c \
			lstprinter.c \
			smista.c \
			utils.c \
			utils2.c \
			pidutils.c \
			redirutils.c \
			double_redir.c \
			rev_redirection.c \
			ourturn.c \
			ourturn2.c \
			ft_read_line.c \
			ft_read_history.c \
			env_manager.c \
			expand_var.c \

OBJ		=	$(SRCS:.c=.o)

%.o 	:	%.c
			$(CC) $(CFLAGS) -c $< -o $@

$(NAME)	:	$(OBJ)
			make -C ${FT_DIR}
			$(CC) $(CFLAGS) -I $(FT_DIR) $(OBJ) $(FT_LNK) -o $(NAME) 

all		:	$(NAME)

clean	:
			$(RM) *.txt
			$(RM) $(OBJ)
			make clean -C $(FT_DIR)

fclean	:	clean
			$(RM) $(NAME)
			make fclean -C $(FT_DIR)

re		:	fclean all

run		:	${NAME}
			./${NAME}

v		:	${NAME}
			valgrind --leak-check=full \
			--show-leak-kinds=all \
			--dsymutil=yes \
			--trace-children=yes \
			--track-fds=yes \
			--track-origins=yes \
			--verbose \
			--verbose \
			--log-file=./valgrind-out.txt \
			./${NAME} && cat ./valgrind-out.txt

.PHONY		:	all clean fclean re run
