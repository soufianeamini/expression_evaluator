PARSER	=	parser.c

LEXER	=	lexer.c

DATA	=	tree.c token.c

SRCS	=	main.c $(addprefix lexer/, $(LEXER)) $(addprefix parser/, $(PARSER)) $(addprefix data_structs/, $(DATA))

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
