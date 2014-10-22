#ifndef _SERVER_H_
#define _SERVER_H_

#include "my.h"
#include <signal.h>
/*
 * Author: Jeff Mariconda
 * Class: CS-392
 *
 *
 */

typedef struct s_env {
  pid_t clipid;
  char done;
} gl_env;

//
void get_char(int);

#endif

#ifndef _CLIENT_H_
#define _CLIENT_H_

typedef struct s_ack {
  char ack;
} gl_ack;

//takes a char and a process id and sends the char bit-by-bit to the pid
void send_char(char, pid_t);

#endif 

