#include "my.h"
#include <signal.h>

/*
 * Author: Jeff Mariconda
 * Class: CS-392
 *
 *  
 */
int main() 
{
  int i;

  my_str("Server pid: ");
  my_int(getpid());
  signal(SIGINT, bye());

  while (1) {
    //initialize stuff
    signal(SIGUSR1, getclipid());
    signal(SIGUSR2, getclipid());
    for (i = 0 ; i < (8 * sizeof(int)) ; i++)
      pause();
    signal(SIGUSR1, getmsg());
    signal(SIGUSR2, getmsg());
    kill(gl_env.clipid, SIGUSR1);
    while (!gl_env.done)
      pause();
    my_str("\n\n");
  }
  return 0;
}
