#include "myselect.h"
/*
 * Author: Jeff Mariconda
 * Class: CS-392
 *
 * Moves the cursor down. If it is at the last elem in the column, loops it to the top
 * of the column to the right.
 */
void movedown() 
{
  if (gl_env.pos < gl_env.nbelems - 1) {
    refreshout(gl_env.pos);
    gl_env.pos++;
    refreshin();
  }
}
