#include "myselect.h"
/*
 * Author: Jeff Mariconda
 * Class: CS-392
 *
 * Pre: Takes a char* to check.
 * Post: Checks the char* and acts accordingly.
 */
void check_char(char *in)
{
  if (in != NULL) {
    if (!my_strcmp(in, KR))
      moveright();
    else if (!my_strcmp(in, KL))
      moveleft();
    else if (!my_strcmp(in, KU))
      moveup();
    else if (!my_strcmp(in, KD))
      movedown();
    else if (!my_strcmp(in, " "))
      doselect();
    else if (!my_strcmp(in, "\E"))
      getout('0');
    else if (!my_strcmp(in, "\n"))
      getout('1');
  }
}
