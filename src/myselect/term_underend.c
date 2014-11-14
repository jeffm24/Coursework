#include "myselect.h"
/*
 * Author: Jeff Mariconda
 * Class: CS-392
 *
 * De-Activates underlining.
 */
void term_underend()
{
  tputs(gl_env.under_end, 1, my_termprint);
}
