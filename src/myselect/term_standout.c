#include "myselect.h"
/*
 * Author: Jeff Mariconda
 * Class: CS-392
 *
 * Activates highlighting.
 */
void term_standout()
{
  tputs(gl_env.standout, 1, my_termprint);
}
