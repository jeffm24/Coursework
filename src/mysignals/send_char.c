#include "mysignals.h"

/*
 * Author: Jeff Mariconda
 * Class: CS-392
 *
 * Pre: Takes a char c to send and a pid_t to send to.
 * Post: 
 */
void send_char(char c, pid_t serverpid)
{
  char mask = 128;
  char i;

  for (i = 0 ; i < 8 ; i++) {
    if (c & mask) 
      kill(serverpid, SIGUSR1);
    else
      kill(serverpid, SIGUSR2);

    c << 1;
    pause;
  }
}
