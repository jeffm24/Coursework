#include "myselect.h"
/*
 * Author: Jeff Mariconda
 * Class: CS-392
 *
 * Redraws an element at the given pos without an underline.
 */
void refreshout(int pos)
{
  term_move_to_item(pos);
  term_underend();
  if (gl_env.elements[pos].mode) 
    term_standout();

  my_str(gl_env.elements[pos].name);
 
  term_standend();
}
