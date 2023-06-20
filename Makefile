PARSER	=	parser.c

LEXER	=	lexer.c

TOKEN	=	token.c

TREE	=	tree.c

SRCS	=	main.c $(addprefix lexer/, $(LEXER)) $(addprefix token/, $(TOKEN)) $(addprefix parser/, $(PARSER)) $(addprefix tree/, $(TREE))

OBJS	=	$(SRCS:.c=.o)

HEADER	=	eval.h

NAME	=	evaluator

CC		=	cc

CFLAGS	=	-Wall -Wextra -Werror -g

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
