#include "myselect.h"
/*
 * Author: Jeff Mariconda
 * Class: CS-392
 *
 * Makes the cursor visible.
 */
void term_ve()
{
  tputs(gl_env.cursoron, 1, my_termprint);
}
