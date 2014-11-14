#include "myselect.h"
/*
 * Author: Jeff Mariconda
 * Class: CS-392
 *
 * A program that takes args as input and displays them in re-flowable rows and columns 
 *  that you can navigate around and select things.
 */
int main(int argc, char **argv)
{
  int n;
  char buf[READMIN + 5];

  if (argv != NULL && argc > 1) {
    signal(SIGWINCH, show_elems);
    
    init_caps();
    init_terminal();
    setup_elems(argc - 1, &argv[1]);
    term_vi();
    show_elems();
    
    while (1) {
      n = read(0, &buf, READMIN + 5);
      buf[n] = '\0';
      check_char(buf);
    }    
  } else {
    my_str("\nERROR: Invalid Input. Please use the following format:\n\t./myselect [args]\n");
    exit(1);
  }
  return 0;
}
