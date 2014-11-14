#Makefile for myselect
NAME = myselect
SRC = my_select.c init_terminal.c restore_terminal.c term_get_cap.c init_caps.c my_termprint.c \
	term_clear.c term_vi.c term_ve.c check_char.c show_elems.c refreshin.c \
	refreshout.c moveup.c movedown.c moveleft.c moveright.c doselect.c getout.c \
	setup_elems.c term_move_to_item.c term_move.c term_underline.c term_standout.c \
	term_standend.c term_underend.c 
OBJ = $(SRC_S:.c=.o)
RM = rm -fv

all: $(OBJ)
	cc -g -L../../lib -I../../include $(SRC) -ltermcap -lmy -o $(NAME)

clean:
	-$(RM) *~
	-$(RM) \#*
	-$(RM) *.o
	-$(RM) *.core

fclean: clean
	-$(RM) $(NAME)

re: fclean all
