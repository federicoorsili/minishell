NAME	=	libft.a

SRCSB	=	$(wildcard ft_lst*.c)
SRCS	=	$(filter-out $(SRCSB), $(wildcard *.c))
OBJ		=	$(SRCS:.c=.o)
OBJB	=	$(SRCSB:.c=.o)

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror

.c.o	:
			$(CC) $(CFLAGS) -c $<

$(NAME)	:	$(OBJ)
			ar rc $(NAME) $(OBJ)

all		:	$(NAME)

bonus	:	$(NAME) $(OBJ) $(OBJB)
			ar rc $(NAME) $(OBJ) $(OBJB)

clean	:
			rm -f $(OBJ) $(OBJB)

fclean	:	clean
			rm -f $(NAME)

re		:	fclean all

.PHONY	:	all bonus clean fclean re