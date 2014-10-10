# Makefile for the pipes main
NAME = pipes
OBJ = $(SRC:.c=.o)
RM = rm -fv

all:
	cc -ggdb -L../../lib -I../../include my_pipes.c -lmy -o $(NAME)

clean:
	-$(RM) *~
	-$(RM) \#*
	-$(RM) *.o
	-$(RM) *.core

fclean: clean
	-$(RM) $(NAME)

re: fclean all
