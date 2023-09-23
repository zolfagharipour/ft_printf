NAME		= libftprintf.a
INC			= ft_printf.h
CC			= cc
CFLAGS		=
AR			= ar rc
RM			= rm -rf

SRCS		= $(wildcard *.c)

OBJS		= $(SRCS:.c=.o)

all:	${NAME} 

$(NAME): $(OBJS)
	make -C ./libft 
	cp libft/libft.a libftprintf.a
	$(AR) $(NAME) $(OBJS)

%.o: %.c $(INC) 
	$(CC) $(CFLAGS) -c $< -o $@

clean:	
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

bonus: re
