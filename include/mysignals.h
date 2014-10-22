#ifndef _SIGNALS_H_
#define _SIGNALS_H_

#include "my.h"
#include <signal.h>
/*
 * Author: Jeff Mariconda
 * Class: CS-392
 *
 * Program to send strings from client program to 
 * 	server program using only signals.
 */

typedef struct s_env {
  pid_t clipid;
  char done;
  char ack;
} t_env;

t_env gl_env;

//takes an int signal and 
void get_char(int);

//gets the pid of the client and returns it
void get_clipid(int);

//prints goodbye message for server and ends the program 
void sbye();

//takes a char and a pid and sends the char bit-by-bit to the pid
void send_char(char, pid_t);

//sends the given pid from the client to the server
void send_pid(pid_t);

//sets gl_env.ack to 1 to acknowledge client connection to server
void acknowledge();

//prints goodbye message for client and ends the program
void cbye();

#endif
