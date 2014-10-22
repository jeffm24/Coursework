#include "mysignals.h"

/*
 * Author: Jeff Mariconda
 * Class: CS-392
 *
 * Pre: Takes a char c to send and a pid_t to send to.
 * Post: Sends the char bit-by-bit to the server using SIGUSR1 for 1 and SIGUSR2 for 0.
 */
void send_char(char c, pid_t spid)
{
	char mask = 0x80;
	char i;

	for (i = 0 ; i < 8 ; i++) {
		usleep(5000);
		if (c & mask) 
			kill(spid, SIGUSR1);
		else
			kill(spid, SIGUSR2);

		c <<= 1;
		alarm(3);
		pause;
	}
}
