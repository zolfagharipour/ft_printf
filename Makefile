NAME		= libftprintf.a
INC			= ft_printf.h
CC			= cc
CFLAGS		=
AR			= ar rc
RM			= rm -rf

SRCS		= $(wildcard *.c)

OBJS		= $(SRCS:.c=.o)

all:	${NAME} 

$(NAME):
	cc $(SRCS) libft.a -L -lft
	./a.out

clean:	
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

bonus: re
