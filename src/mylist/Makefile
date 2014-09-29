#Makefile for libmylist.a
NAME = libmylist.a
SRC = new_node.c add_node.c add_elem.c append.c add_node_at.c remove_node.c remove_node_at.c \
	remove_last.c count_nodes.c empty_list.c node_at.c elem_at.c traverse_int.c traverse_char.c \
	traverse_string.c
OBJ = $(SRC:.c=.o)
RM = rm -fv
INCL = ../../include
LIBR = ../../lib
CFLAGS += -I$(INCL)

all: $(OBJ)
	ar -rc $(LIBR)/$(NAME) $(OBJ)
	ranlib $(LIBR)/$(NAME)

clean:
	-$(RM) *.o
	-$(RM) *.swp
	-$(RM) *~
	-$(RM) \#*
	-$(RM) *.core

fclean: clean
	-$(RM) $(LIBR)/$(NAME)

re: fclean all clean
