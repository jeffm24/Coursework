#include "my.h"

/*
  Author: Jeff Mariconda
  Class: cs392

  pre: char* is NULL or valid string 
  post: return the length of the string or -1 if NULL
*/

int my_strlen(char* str)
{
  int i;

  if(str != NULL){
    for(i = 0;*str != '\0';i++, str++);    
    return i;
  }else
    return -1;
}
