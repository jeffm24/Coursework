#include "my.h"

/*
  Author: Jeff Mariconda
  Class: cs392

  pre: takes a string to parse and a char to look for
  post: returns the index of the first occurrence of that char from right to left and -1 if it is 
        not there
*/

int my_strpos(char *str, char c)
{
  int i;

  if(str != NULL)
    for(i = 0;*str != '\0';str++, i++)
      if(*str == c)
	return i;

  return -1;
}
