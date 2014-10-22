#Makefile for libmy.a
NAME = libmy.a
SRC = my_char.c my_str.c my_int.c my_num_base.c my_alpha.c my_digits.c my_strlen.c \
	my_revstr.c my_strpos.c my_strrpos.c my_strdup.c my_strcmp.c my_strncmp.c \
	my_strcpy.c my_strncpy.c my_strconcat.c my_strnconcat.c my_strcat.c my_strfind.c \
	my_strrfind.c my_vect2str.c my_str2vect.c xmalloc.c my_freevect.c my_atoi.c
OBJ = $(SRC:.c=.o)
RM = rm -fv
INCL = ../../include
LIBR = ../../lib
TEST = ../../test
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
