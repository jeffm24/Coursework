#Makefile for signals
NAME = mysignals
SRC = server.c client.c
OBJ = $(SRC:.c=.o)
RM = rm -fv

all:
	cc -g -L../../lib -I../../include server.c -lmy -o $(NAME)

clean:
	-$(RM) *~
	-$(RM) \#*
	-$(RM) *.o
	-$(RM) *.core

fclean: clean
	-$(RM) $(NAME)

re: fclean all
