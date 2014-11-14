#include "myselect.h"
/*
 * Author: Jeff Mariconda
 * Class: CS-392
 * 
 * Sets the mode attribute of the element at the current pos.
 */
void doselect()
{
  if (gl_env.elements[gl_env.pos].mode == 0)
    gl_env.elements[gl_env.pos].mode = 1;
  else
    gl_env.elements[gl_env.pos].mode = 0;
}
