#include "my.h"

/*
  Author: Jeff Mariconda
  Class: cs392

  pre: takes a char* or NULL, but not a literal string
  post: reverses the string and returns its length
*/

int my_revstr(char *str)
{
  int l, r;
  char temp;

  if(str != NULL){
    for(r = my_strlen(str) - 1,l = 0 ; l <= r ; l++,r--){
      temp = str[l];
      str[l] = str[r];
      str[r] = temp;
    }
  }
  return my_strlen(str);
}
