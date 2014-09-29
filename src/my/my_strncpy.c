#include "my.h"

/*
  Pre: Takes one string/NULL as src, one as dst, and a max length of chars to copy.
  Post: Copies the contents of the src string into dst, while not exceeding n chars, and returns dst. 
*/

char *my_strncpy(char *dst, char *src, unsigned int n)
{
  int i, l;

  if(dst != NULL && src != NULL){
    l = (n >= my_strlen(src)) ? my_strlen(src) : (n - 1);
    for(i = 0 ; i <= l ; i++)
      dst[i] = src[i];
  }

  return dst;
}
