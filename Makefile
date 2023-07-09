NAME		= a.out
INC			= ft_printf.h
CC			= gcc
CFLAGS		= -L -lft
AR			= ar rc
RM			= rm -rf

SRCS		= $(wildcard *.c)

OBJS		= $(SRCS:.c=.o)

all:	${NAME} 

$(NAME): ${SRCS} $(INC)
	$(CC) $(SRCS) libft.a $(CFLAGS)
	./a.out


clean:	
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

bonus: re
