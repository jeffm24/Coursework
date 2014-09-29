#include "my.h"

/*
  Pre: Takes two strings/NULLs to concatinate.
  Post: Concatinates the second string to the end of the first and returns the first string.
*/

char *my_strcat(char *s1, char *s2)
{
  int i;

  if(s1 != NULL && s2 != NULL){
    i = my_strlen(s1);
    for(; *s2 != '\0' ; s2++,i++)
      s1[i] = *s2;
    s1[i] = '\0';
  }
  return s1;
}
