#include "myselect.h"
/*
 * Author: Jeff Mariconda
 * Class: CS-392
 *
 * Writes the given int directly to the terminal.
 */
int my_termprint(int c)
{
  return write(1, &c, 1);
}
