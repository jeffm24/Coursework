#include "mysignals.h"

/*
 * Author: Jeff Mariconda
 * Class: CS-392
 *
 * Pre: Takes an int signal
 * Post: Shifts the clipid one bit to the left and adds a 1 if SIGUSR1 is received
 */
void get_clipid(int sig) {
	gl_env.clipid <<= 1;

    if (sig == SIGUSR1) {
        gl_env.clipid |= 1;
    }
}
