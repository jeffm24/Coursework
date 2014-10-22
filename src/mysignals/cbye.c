#include "mysignals.h"

/*
 * Author: Jeff Mariconda
 * Class: CS-392
 *
 * Prints goodbye message and ends the client. 
 * To be used if connection times out.
 */
void cbye()
{
	my_str("\n\nConnection Timed Out. Goodbye.\n\n");	
	exit(0);
}
