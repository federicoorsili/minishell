NAME	=	minishell
LIBFT	=	./libft/libft.a
CC		=	gcc
CFLAGS	=	
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
ft_read_line.c \


OBJ		=	$(SRCS:.c=.o)

%.o	:	%.c
			$(CC) $(CFLAGS) -c $< -o $@

$(NAME)	:	$(OBJ)
			make -C ./libft
			$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT)

all		:	$(NAME)

bonus	:	all

clean	:
			make -C clean
			$(RM) $(OBJ)
			make clean -C ./libft

fclean	:	clean
			$(RM) $(NAME)
			make fclean -C ./libft

re		:	fclean all

.PHONY	:	all bonus clean fclean re
