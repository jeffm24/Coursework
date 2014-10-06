#include "my.h"

/*
 * Author: Jeff Mariconda
 * Class: CS392
 *
 * Program that takes a vector as args from the command line, converts it to a string, forks the process twice and passes the string between 
 * the three processes.
 */
int main(int argc, char **argv)
{
  int pid, pid2, n;
  int fds[2], fds2[2];
  char *str, *buff;

  if (argc > 1) {
    pipe(fds);
    buff = xmalloc(256 * sizeof(char));

    if ((pid = fork()) < 0) {
      my_str("FAILED FORK.");
      exit(0);
    } else if (pid > 0) {
      str = my_vect2str(&argv[1]);
      
      my_str("This is grandpa, sending \"");
      my_str(str);
      my_str("\" to parent.\n");
      
      close(fds[0]);
      write(fds[1], str, my_strlen(str)); 
      
      wait();
      my_str("\nParent dead.\n");
    } else {
      pipe(fds2);
      
      if ((pid2 = fork()) < 0) {
	my_str("FAILED FORK.");
	exit(0);
      } else if (pid2 > 0) {
	close(fds[1]);
	if ((n = read(fds[0], buff, 256)) < 0) {
	  my_str("READ ERROR.");
	  exit(0);
	}
	str = buff;

	my_str("This is parent, receiving \"");
	my_str(str);
	my_str("\" from grandpa and sending to child.\n");
	
	close(fds2[0]);
	write(fds2[1], str, my_strlen(str)); 
	
	wait();
	my_str("\nChild dead.\n");
      } else {
	close(fds2[1]);
	if ((n = read(fds2[0], buff, 256)) < 0) {
	  my_str("READ ERROR.");
	  exit(0);
	}
	str = buff;

	my_str("This is child, receiving \"");
	my_str(str);
	my_str("\" from parent.\n");
      }
    }
  } else {
    my_str("ERROR. Invavlid Usage.\nUse: ./mypipes arg1 [arg2] [arg3] ...\n");
    exit(0);
  }

  return 0;
}
