#include "my.h"

/*
  Pre: Takes two strings/NULLS to compare.
  Post: Returns -1 if s1 < s2, 0 if s1 == s2, and 1 if s1 > s2.
*/

int my_strcmp(char *s1, char *s2)
{
  if(s1 == NULL && s2 == NULL)
    return 0;
  else if(s1 == NULL)
    return -1;
  else if(s2 == NULL)
    return 1;

  for(;*s1 == *s2 ; s1++,s2++)
    if(*s1 == '\0')
      return 0;

  if(*s1 > *s2)
    return 1;
  else 
    return -1;
}
