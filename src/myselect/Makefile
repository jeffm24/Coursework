#Makefile for myselect
NAME = server
SRC = 
OBJ = $(SRC_S:.c=.o)
RM = rm -fv

all: $(OBJ)
	cc -g -L../../lib -I../../include $(SRC) -lmy -o $(NAME)

clean:
	-$(RM) *~
	-$(RM) \#*
	-$(RM) *.o
	-$(RM) *.core

fclean: clean
	-$(RM) $(NAME)

re: fclean all
