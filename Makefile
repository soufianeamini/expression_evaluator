SRCS	=	main.c

OBJS	=	$(SRCS:.c=.o)

HEADER	=	eval.h

NAME	=	evaluator

CC		=	cc

CFLAGS	=	-Wall -Wextra -Werror

LFLAGS	=	-lreadline

all:	$(NAME)

$(NAME):	$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LFLAGS) -o $@

%.o:	%.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
