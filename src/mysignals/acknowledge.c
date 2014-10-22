#include "mysignals.h"

/*
 * Author: Jeff Mariconda
 * Class: CS-392
 *
 * Sets the global acknowledgment variable to 1 to acknowledge client connection to server
*/
void acknowledge()
{
	gl_env.ack = 1;
}
