#include "myselect.h"
/*
 * Author: Jeff Mariconda
 * Class: CS-392
 *
 * Moves the cursor one column to the right. If it is in the last column, moves it to 
 * the last elem.
 */
void moveright() 
{
  if (gl_env.pos < gl_env.nbelems - 1) {
    refreshout(gl_env.pos);

    if ((gl_env.pos + gl_env.win.ws_row) > gl_env.nbelems - 1)
      gl_env.pos = gl_env.nbelems - 1;
    else
      gl_env.pos += gl_env.win.ws_row;
    
    refreshin();
  }
}
