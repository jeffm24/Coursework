#include "my.h"

/*
  Pre: Takes a string to parse and a character to search for.
  Post: Returns a pointer to the first instance of that character from left to right and NULL if it's not there.
*/

char *my_strrfind(char *s, char c)
{
  int i = my_strrpos(s, c);

  if(i >= 0)
    return (s + i);
  else
    return NULL;
}
