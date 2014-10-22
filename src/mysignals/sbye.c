#include "mysignals.h"

/*
 * Author: Jeff Mariconda
 * Class: CS-392
 *
 * Prints goodbye message and ends the server.
 * To be used if SIGINT is received.
 */
void sbye()
{
	my_str("\n\nReceived Interrupt: Server Stopped.\n\n");	
	exit(0);
}
