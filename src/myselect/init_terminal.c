#include "myselect.h"
/*
 * Author: Jeff Mariconda
 * Class: CS-392
 *
 * Initializes the terminal for non-canonical reading and sets fd 1 to
 *  be the terminal file descriptor.
 */
void init_terminal()
{
  struct termio line;
  char *name;
  int fd;
  
  //backup current canonical input mode
  ioctl(0, TCGETA, &gl_env.line_backup);
  ioctl(0, TCGETA, &line);
    
  //set input mode to non-canonical
  line.c_lflag &= ~(ICANON | ECHO | ISIG);
  line.c_cc[VMIN] = READMIN;
  line.c_cc[VTIME] = READTIME;
  ioctl(0, TCSETA, &line);

  //open terminal for writing
  name = ttyname(0);
  fd = open(name, O_WRONLY);

  //change file descriptor 1 to terminal
  gl_env.stdio_backup = dup(1);
  dup2(fd, 1);
}
