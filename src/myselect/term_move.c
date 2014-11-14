#include "myselect.h"
/*
 * Author: Jeff Mariconda
 * Class: CS-392
 *
 * Moves the cursor to the given position.
 */
void term_move(int x, int y)
{
  tputs(tgoto(gl_env.move, x, y), 1, my_termprint); 
}
