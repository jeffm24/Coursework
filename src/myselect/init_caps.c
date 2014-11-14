#include "myselect.h"
/*
 * Author: Jeff Mariconda
 * Class: CS-392
 *
 * Backup old termcaps and set the new ones.
 */
void init_caps()
{
  char blockptr[2048];
  char *term;
  
  //load current TERM environment variable
  if ((term = getenv("TERM")) == NULL) {
    my_str("\nERROR: Unable to get TERM env variable.\n");
    exit(1);
  }
  tgetent(blockptr, term);

  //load termcaps into global struct
  gl_env.left = term_get_cap(LEFT);
  gl_env.right = term_get_cap(RIGHT);
  gl_env.up = term_get_cap(UP);
  gl_env.down = term_get_cap(DOWN);
  gl_env.underline = term_get_cap(UNDERLINE);
  gl_env.under_end = term_get_cap(UNDER_END);
  gl_env.standout = term_get_cap(STANDOUT);
  gl_env.stand_end = term_get_cap(STAND_END);
  gl_env.move = term_get_cap(MOVE);
  gl_env.clear = term_get_cap(CLEAR);
  gl_env.cursoroff = term_get_cap(CURSOROFF);
  gl_env.cursoron = term_get_cap(CURSORON);
}
