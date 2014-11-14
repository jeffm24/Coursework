#include "myselect.h"
/*
 * Author: Jeff Mariconda
 * Class: CS-392
 *
 * Pre: Takes an int position to move to in the array
 * Post: Sets the pos to that position
 */
void term_move_to_item(int pos) {
  if (pos >= 0 && pos < gl_env.nbelems) {
    gl_env.pos = pos;
    term_move(gl_env.elements[pos].x, gl_env.elements[pos].y);
  }
}
