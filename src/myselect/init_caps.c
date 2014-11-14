#include "myselect.c"
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
  
  //get current termcaps
  if ((term = getenv("TERM")) == NULL) {
    my_str("\nERROR: Unable to get termcaps.\n");
    exit(1);
  }
  //backup current termcaps
  tgetent(blockptr, term);
  
  gl_env.left = term_get_cap(LEFT);
  gl_env.right = term_get_cap(RIGHT);
  gl_env.up = term_get_cap(UP);
  gl_env.down = term_get_cap(DOWN);
  gl_env.esc = term_get_cap(ESC);
  gl_env.underline = term_get_cap(UNDERLINE);
  gl_env.under_end = term_get_cap(UNDER_END);
  gl_env.standout = term_get_cap(STANDOUT);
  gl_env.stand_end = term_get_cap(STAND_END);
  gl_env.move = term_get_cap(MOVE);
  gl_env.clear = term_get_cap(CLEAR);
  gl_env.cursoroff = term_get_cap(VICAP);
  gl_env.cursoron = term_get_cap(VECAP);
}
