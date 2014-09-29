#include "my.h"

/*
  Pre: Takes one string/NULL as src and one as dst.
  Post: Copies the contents of the src string into the dst string and returns dst.
*/

char *my_strcpy(char *dst, char *src)
{
  int i;

  if(dst != NULL && src != NULL){
    for(i = 0 ; src[i] != '\0' ; i++)
      dst[i] = src[i];
    dst[i] = '\0';
  }
  return dst;
}
