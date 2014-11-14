#include "myselect.h"
/*
 * Author: Jeff Mariconda
 * Class: CS-392
 *
 * Pre: Takes a char c to determine whether to exit on an ESC or ENTER
 * Post: If c == 0, exit on ESC and print nothing.
 *       If c == 1, exit on ENTER and print all selected elements.
 */
void getout(char c)
{
  int i;
  
  term_clear();
  if (c) {
    //enter
    restore_terminal();

    for (i = 0 ; i < gl_env.nbelems ; i++) {
      if (gl_env.elements[i].mode) {
	my_str(gl_env.elements[i].elem);
	my_str(" ");
      }
    }
    my_str("\n");
    
    exit(0);
  } else {
    //escape
    restore_terminal();
    exit(0);
  }
}
