NAME = test
LIB = lib$(NAME)
TARBALL = jmariconda-$(NAME).tar.gz
OBJ = $(SRC:.c=.o)
RM = rm -fv

all:
	cc -ggdb -L../lib -I../include testmy2.c -lmy -o $(NAME)

clean:
	-$(RM) *~
	-$(RM) \#*
	-$(RM) *.o
	-$(RM) *.core

fclean: clean
	-$(RM) $(NAME)

re: fclean all

submit: fclean
	tar cvzf $(TARBALL) *
