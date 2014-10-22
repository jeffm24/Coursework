#Makefile for signals
NAME_S = server
NAME_C = client
SRC_S = server.c get_char.c sbye.c get_clipid.c
SRC_C = client.c send_char.c cbye.c acknowledge.c send_pid.c
OBJS = $(SRC_S:.c=.o)
OBJC = $(SRC_C:.c=.o)
RM = rm -fv

server: $(OBJ_S)
	cc -g -L../../lib -I../../include $(SRC_S) -lmy -o $(NAME_S)

client: $(OBJ_C)
	cc -g -L../../lib -I../../include $(SRC_C) -lmy -o $(NAME_C)

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
