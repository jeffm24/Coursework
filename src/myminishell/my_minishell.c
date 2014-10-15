#include "my.h"

/*
 * Author: Jeff Mariconda
 * Class: CS392
 * 
 * A basic shell for running termnial commands.
 */
int main() 
{
  char **v;
  char buff[256];
  int pid;
  int i;
  
  my_str("\n--------------Welcome to Minishell v2.3434.5346.32.214.24.35--------------\n\n");
  while (1) {
    my_str(getcwd(buff, 256));
    my_str("> ");
    
    if (read(0, buff, 256) < 0) {
      my_str("\nREAD FAILED.\n\n");
      exit(0);
    } 
    v = my_str2vect(buff); 

    if (my_strcmp(v[0], "cd") == 0) {

      if(chdir(v[1]) != 0)
	my_str("\nInvalid path argument.\n\n");

    } else if (my_strcmp(v[0], "exit") == 0) {

      my_str("\nThanks for using Minishell v.2.3434.5346.32.214.24.35. Have a nice day.\n");
      my_str("--------------------------------------------------------------------------\n\n");
      exit(0);

    } else {

      if ((pid = fork()) < 0) {
	my_str("\nFORK FAILED.\n\n");
	exit(0);
      } else if (pid == 0) {
	my_char('\n');
	if (execvp(v[0], v) < 0)
	  my_str("\nInvalid command.\n\n");
	my_freevect(v);
	break;
      } else {
	wait();
      }
    
    }
    my_freevect(v);
    my_char('\n');
  }
  
  return 0;
}
