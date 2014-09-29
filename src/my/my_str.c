#include "my.h"

/*
  Author: Jeff Mariconda
  Class: cs392

  pre: char* is null or valid string
  post: prints string to stdout
*/

void my_str(char* str)
{
  if(str != NULL)
    while(*str)
      my_char(*(str++));
}
