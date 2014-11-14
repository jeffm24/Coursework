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
    if (my_strcmp(in, KR) == 0 && gl_env.flag != 1)
      moveright();
    else if (my_strcmp(in, KL) == 0 && gl_env.flag != 1)
      moveleft();
    else if (my_strcmp(in, KU) == 0 && gl_env.flag != 1)
      moveup();
    else if (my_strcmp(in, KD) == 0 && gl_env.flag != 1)
      movedown();
    else if (my_strcmp(in, " ") == 0 && gl_env.flag != 1)
      doselect();
    else if (my_strcmp(in, "\E") == 0)
      getout(0);
    else if (my_strcmp(in, "\n") == 0)
      getout(1);
  }
}
