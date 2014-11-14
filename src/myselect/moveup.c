#include "myselect.h"
/*
 * Author: Jeff Mariconda
 * Class: CS-392
 *
 * Moves the cursor up (to the previous element in sequence).
 */
void moveup() 
{
  if (gl_env.pos > 0) {
    refreshout(gl_env.pos);
    gl_env.pos--;
    refreshin();
  }
}
