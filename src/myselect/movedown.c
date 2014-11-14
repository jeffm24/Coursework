#include "myselect.h"
/*
 * Author: Jeff Mariconda
 * Class: CS-392
 *
 * Moves the cursor down (to the next element in sequence).
 */
void movedown() 
{
  if (gl_env.pos < gl_env.nbelems - 1) {
    refreshout(gl_env.pos);
    gl_env.pos++;
    refreshin();
  }
}
