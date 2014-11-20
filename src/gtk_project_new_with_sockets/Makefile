#Makefile for mysockets
NAME_S = server
NAME_C = client
SRC_S = server.c
SRC_C = client.c destroy_cb.c delete_cb.c sendclick_cb.c connectclick_cb.c quitclick_cb.c \
	closepopup_cb.c okconnect_cb.c disconnect.c
OBJS = $(SRC_S:.c=.o)
OBJC = $(SRC_C:.c=.o)
RM = rm -fv

server: $(OBJ_S)
	cc -g -L../../lib -I../../include $(SRC_S) -lmy -o $(NAME_S)

client: $(OBJ_C)
	cc -g -L../../lib -I../../include $(SRC_C) `pkg-config --cflags --libs gtk+-2.0` -lmy -o $(NAME_C)

all: server client

clean:
	-$(RM) *~
	-$(RM) \#*
	-$(RM) *.o
	-$(RM) *.core

fclean: clean
	-$(RM) $(NAME_S)
	-$(RM) $(NAME_C)

re: fclean all
