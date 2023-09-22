NAME		=	libft.a
INC			=	libft.h
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
AR			=	ar rc
RM			=	rm -f

BONSRCS		=	$(wildcard *lst*.c)
SRCS		=	$(filter-out $(BONSRCS), $(wildcard *.c))
OBJS		=	$(SRCS:.c=.o)
BONOBJS		=	$(BONSRCS:.c=.o)

.PHONY:		all clean fclean re bonus

all:	$(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

bonus:	$(BONOBJS) $(OBJS)
	$(AR) $(NAME) $(BONOBJS) $(OBJS)

%.o: %.c $(INC)
	$(CC) $(CFLAGS) -c $< -o $@

clean:	
	$(RM) $(OBJS) $(BONOBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all
