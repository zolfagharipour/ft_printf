NAME		= libftprintf.a
INC			= ft_printf.h
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
AR			= ar rc
RM			= rm -rf

SRC		= $(wildcard *.c)

OBJ		= $(SRCS:.c=.o)

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
