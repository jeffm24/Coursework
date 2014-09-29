#include "my.h"

/*
  Pre: Takes two strings/NULLs and the max number of characters to compare.
  Post: Returns -1 if s1 < s2, 0 if s1 == s2, and 1 if s1 > s2.
*/

int my_strncmp(char *s1, char *s2, unsigned int n)
{
  if(s1 == NULL && s2 == NULL)
    return 0;
  else if(s1 == NULL)
    return -1;
  else if(s2 == NULL)
    return 1;
  else if(n == 0)
    return 0;

  for(;n > 1 && *s1 == *s2 ; s1++,s2++,n--)
    if(*s1 == '\0')
      return 0;

  if(*s1 > *s2)
    return 1;
  else if(*s1 == *s2)
    return 0;
  else
    return -1;
}
