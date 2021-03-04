NAME	=	minishell
LIBFT	=	./libft/libft.a
CC		=	gcc
CFLAGS	=	
RM		=	rm -f
SRCS	=	minishell.c \
get_next_line.c \
get_next_line_utils.c \
cmds_gestor.c \
scmd_gestor.c \
parsing.c \
splitcmd.c \
splitterdot.c \
lstprinter.c \
smista.c \

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
