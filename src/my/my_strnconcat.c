#include "my.h"

/*
  Pre: Takes two strings/NULLs to be concatinated and the max number of chars to concatinate from the second string.
  Post: Creates a new string that is the concatination of the two according to the constraints and returns it.
*/

char *my_strnconcat(char *s1, char *s2, unsigned int n)
{
  char *s;
  int i, l;

  if(s1 == NULL && s2 == NULL)
    return NULL;

  l = my_strlen(s1) + ((n >= my_strlen(s2)) ? (my_strlen(s2) + 1) : n);
  s = xmalloc(l);
  i = 0;
  if(s1 != NULL)
    for(; *s1 != '\0' ; s1++,i++)
      s[i] = *s1;
  if(s2 != NULL)
    for(; i <= l ; s2++,i++)
      s[i] = *s2;
  s[i] = '\0';

  return s;
}
