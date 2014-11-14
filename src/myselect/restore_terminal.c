#include "myselect.h"
/*
 * Author: Jeff Mariconda
 * Class: CS-392
 *
 * Restores all of the default terminal properties.
 */
void restore_terminal()
{
  term_ve();
  ioctl(0, TCGETA, &gl_env.line_backup);
  dup2(gl_env.stdio_backup, 1);
}
