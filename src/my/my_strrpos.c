#include "my.h"

/*
  Author: Jeff Mariconda
  Class: cs392

  pre: takes a string to parse and a character to search for
  post: returns the first occurance of that character from right to left or -1 if it's not there
*/

int my_strrpos(char *str, char c)
{
  int i, pos;
  
  pos = -1;
  if(str != NULL){
    for(i = 0 ; str[i] != '\0' ; i++)
      if(str[i] == c)
	pos = i;
  }
  return pos;
}
