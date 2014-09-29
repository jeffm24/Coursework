#include "my.h"

/*
  Author: Jeff Mariconda
  Class: cs392

  pre: takes no input
  post: prints all digits from 0-9
*/

void my_digits()
{
  char c;

  for(c = '0' ; c <= '9' ; c++)
    my_char(c);
}
