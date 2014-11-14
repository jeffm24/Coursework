#include "myselect.h"
/*
 * Author: Jeff Mariconda
 * Class: CS-392
 *
 * Moves the cursor up. If it is at the first elem in the column, loops it to the bottom
 * of the column to the left.
 */
void moveup() 
{
  if (gl_env.pos != 0) {
    refreshout(gl_env.pos);
    gl_env.pos--;
    refreshin();
  }
}
