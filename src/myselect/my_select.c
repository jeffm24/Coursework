#include "myselect.h"
/*
 * Author: Jeff Mariconda
 * Class: CS-392
 *
 *
 *
 *
 */
int main(int argc, char **argv)
{
  int i;

  if (argv != NULL && argc > 1) {
    signal(SIGWINCH, show_elems);
    init_caps();
    init_terminal();
    ioctl(0, TIOGWINSZ, &gl_env.win);

    setup_elems(argc - 1, &argv[1]);

    term_vi();
    show_elems();
    
    while (1) {

    }
    
  } 
  return 0;
}
