NAME	=	minishell
CC		=	gcc #-pedantic -g
FT_DIR	=	libft
FT_LNK	=	-L ${FT_DIR} -lft
CFLAGS	=	-Wall -Wextra -Werror	
RM		=	rm -f
SRCS	=	minishell.c \
			parsing.c \
			splitcmd.c \
			splitterdot.c \
			smista.c \
			utils.c \
			utils2.c \
			pidutils.c \
			redirutils.c \
			double_redir.c \
			rev_redirection.c \
			ourturn.c \
			ourturn2.c \
			ourturn3.c \
			ourturn4.c \
			ft_read_line.c \
			ft_read_history.c \
			env_manager.c \
			expand_var.c \
			free_exit.c \
			echo_utils.c \
			print_open.c \
			ft_swap_buffer.c \
			ft_cmd_readline_1.c \
			ft_cmd_readline_2.c \
			pipe.c \
			syscall.c \
			double_redir_2.c

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

run		:	$(NAME)
			./$(NAME)
			
stest		:	$(NAME)
			bash _TESTER.sh
			@cp _test.txt _testreal.txt
			@rm _test.txt
			./minishell _TESTER.sh
			@echo "\nDIFFERENZE:\n"
			@diff _test.txt _testreal.txt
			
test		:	$(NAME)
			bash _TESTER.sh
			@cp _test.txt _testreal.txt
			@rm _test.txt
			./minishell _TESTER.sh
			@echo "\nDIFFERENZE:\n"
			@diff _test.txt _testreal.txt
			@rm _test.txt _testreal.txt

v		:	$(NAME)
			valgrind --leak-check=full \
			--show-leak-kinds=all \
			--log-file=./valgrind-out.txt \
			./$(NAME) && cat ./valgrind-out.txt

.PHONY		:	all clean fclean re run test v stest
