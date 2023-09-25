NAME		= libftprintf.a
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
AR			= ar rsc
RM			= rm -f

SRCS		=	ft_conversion.c \
				ft_itoa_s.c \
				ft_conv.c \
				ft_flags.c \
				ft_printf.c \
				ft_subprint.c

OBJS		= $(SRCS:.c=.o)

all:	${NAME} 

$(NAME): $(OBJS)
	make -C ./libft 
	cp libft/libft.a libftprintf.a
	$(AR) $(NAME) $(OBJS)

%.o: %.c 
	$(CC) $(CFLAGS) -c $< -o $@ -I .

clean:	
	make clean -C ./libft
	$(RM) $(OBJS)

fclean:	clean
	make fclean -C ./libft
	$(RM) $(NAME)

re:	fclean all

bonus: ${NAME}
