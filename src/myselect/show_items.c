#include "myselect.h"
/*
 * Author: Jeff Mariconda
 * Class: CS-392
 *
 * Does a full-screen refresh of the rows and columns of elements on the screen.
 */
void show_elems() 
{
  int x, y, i;
  int rowWidth;

  if (gl_env.elements != NULL) {
    i = 0;
    gl_env.flag = 0;
    term_clear();

    for (i = 0, x = 0, y = 0, rowWidth = 0; i < gl_env.nbelems ; i++, y++) {
      if (y >= gl_env.win.win_row) {
	y = 0;
	x += rowWidth + 4;
	rowWidth = 0;
      }

      if (rowWidth < gl_env.elements[i].size)
	rowWidth = gl_env.elements[i].size;

      if (x + rowWidth >= gl_env.win.ws_col) {
	term_clear();
	my_str("Please enlarge the window.");
	gl_env.flag = 1;
	break;
      }

      gl_env.elements[i].x = x;
      gl_env.elements[i].y = y;
      refreshout(i);

      if(!gl_env.flag)
	refreshin();
    }
  }
}
