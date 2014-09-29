#include "my.h"

/*
  Author: Jeff Mariconda
  Class: cs392

  pre: takes a char
  post: prints it to stdout
*/

void my_char(char c)
{
  write(1, &c, 1);
}
