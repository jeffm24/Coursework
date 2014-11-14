#include "myselect.h"
/*
 * Author: Jeff Mariconda
 * Class: CS-392
 *
 * Moves the cursor one column to the left. If it is in the first column, moves it to the 
 * fist elem.
 */
void moveleft() 
{
  if (gl_env.pos > 0) {
    refreshout(gl_env.pos);
    
    if ((gl_env.pos - gl_env.win.ws_row) < 0)
      gl_env.pos = 0;
    else
      gl_env.pos -= gl_env.win.ws_row;

    refreshin();	
  }
}
