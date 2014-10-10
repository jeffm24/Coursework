#Makefile for minishell
NAME = minishell
OBJ = $(SRC:.c=.o)
RM = rm -fv

all:
	cc -g -L../../lib -I../../include my_minishell.c -lmy -o $(NAME)

clean:
	-$(RM) *~
	-$(RM) \#*
	-$(RM) *.o
	-$(RM) *.core

fclean: clean
	-$(RM) $(NAME)

re: fclean all
