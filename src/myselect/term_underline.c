#include "myselect.h"
/*
 * Author: Jeff Mariconda
 * Class: CS-392
 *
 * Activates underlining.
 */
void term_underline()
{
  tputs(gl_env.underline, 1, my_termprint);
}
