#include "myselect.h"
/*
 * Author: Jeff Mariconda
 * Class: CS-392
 *
 * Redraws an element with an underline.
 */
void refreshin()
{
  term_move_to_item(gl_env.pos);
  term_underline();
  if (gl_env.elements[gl_env.pos].mode) 
    term_standout();

  my_str(gl_env.elements[gl_env.pos].name);
 
  term_standend();
  term_underend();
}
