#include "myselect.h"
/*
 * Author: Jeff Mariconda
 * Class: CS-392
 * 
 * Clears the terminal.
 */
void term_clear()
{
  tputs(gl_env.clear, 1, my_termprint);
}
