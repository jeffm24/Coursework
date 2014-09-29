#include "my.h"

/*
  Pre: Takes two strings/NULLs to be concatinated.
  Post: Creates a new string that is the concatination of the two and returns it.
*/

char *my_strconcat(char *s1, char *s2)
{
  char *s;
  int i = 0;
  
  if(s1 == NULL && s2 == NULL)
    return NULL;
  
  s = xmalloc(my_strlen(s1) + my_strlen(s2) + 1);
  if(s1 != NULL)
    for(; *s1 != '\0' ; s1++,i++)
      s[i] = *s1;
  if(s2 != NULL)
    for(; *s2 != '\0' ; s2++,i++)
      s[i] = *s2;
  s[i] = '\0';

  return s;
}
