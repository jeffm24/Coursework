#include "myselect.h"
/*
 * Author: Jeff Mariconda
 * Class: CS-392
 *
 * Pre: Takes a char* cap.
 * Post: Returns the termcap for that char* if possible. 
 */
char *term_get_cap(char *cap)
{
  static char area[2048];
  char *ret;

  if (!(ret = tgetstr(cap, (char**)&area))) {
    my_str("\nERROR: Could not find cap: ");
    my_str(cap);
    my_str("\n");
    restore_terminal();
    exit(1);
  }

  return ret;
}
