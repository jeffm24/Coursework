#include "myselect.h"
/*
 * Author: Jeff Mariconda
 * Class: CS-392
 *
 * De-Activates highlighting.
 */
void term_standend()
{
  tputs(gl_env.stand_end, 1, my_termprint);
}
