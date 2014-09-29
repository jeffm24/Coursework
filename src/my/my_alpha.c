#include "my.h"

/*
  Author: Jeff Mariconda
  Class: cs392

  pre: takes no input
  post: prints all letters from a-z to stdout
*/

void my_alpha()
{
  char c;

  for(c = 'a' ; c <= 'z' ; c++)
    my_char(c);
}
