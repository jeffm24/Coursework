#include "myselect.h"
/*
 * Author: Jeff Mariconda
 * Class: CS-392
 *
 * Pre: Takes an int position to move to in the array
 * Post: Sets the pos to that position
 */
void term_move_to_item(int i) {
  if (i >= 0 && i < gl_env.nbelems) {
    gl_env.pos = i;
  }
}
