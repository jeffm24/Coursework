#include "mysignals.h"

/*
 * Author: Jeff Mariconda
 * Class: CS-392
 *
 * Pre: Takes an int signal.
 * Post: Shifts in a 1 if SIGUSR1 and 0 if SIGUSR2 until the char is full and then prints it.
 */
void get_char(int sig)
{
	static char count = 0;
	static char c = 0;
  
	c <<= 1;
	if (sig == SIGUSR1)
		c |= 1;
	count++;
  
	if (count >= 8) {        
        if (c == '\0')
			gl_env.done = 1;
		else
			my_char(c);
        
        count = 0;
        c = 0;
    }
    
    kill(gl_env.clipid, SIGUSR1);
}
