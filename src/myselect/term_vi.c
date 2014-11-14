#include "myselect.h"
/*
 * Author: Jeff Mariconda
 * Class: CS-392
 *
 * Makes the cursor invisible.
 */
void term_vi()
{
  tputs(gl_env.cursoroff, 1, my_termprint);
}
