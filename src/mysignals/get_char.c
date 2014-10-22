#include "mysignals.h"

/*
 * Author: Jeff Mariconda
 * Class: CS-392
 *
 * Pre: 
 * Post: 
 */
void get_char(int sig)
{
  static char count = 0;
  static char c = 0;
  
  c <<= 1;
  if (sig == SIGUSR1)
    sig |= 1;

  c++;
}
