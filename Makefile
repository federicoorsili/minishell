NAME	=	minishell
LIBFT	=	./libft/libft.a
CC		=	gcc
CFLAGS	=	
RM		=	rm -f
SRCS	=	minishell.c \
get_next_line.c \
get_next_line_utils.c \
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

OBJ		=	$(SRCS:.c=.o)

%.o	:	%.c
			$(CC) $(CFLAGS) -c $< -o $@

$(NAME)	:	$(OBJ)
			make bonus -C ./libft
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
