#include "my.h"

/*
  Pre: Takes a string or a NULL. 
  Post: Duplicates the string and returns the duplicate or returns NULL if given a NULL.
*/

char *my_strdup(char *str)
{
  int i;
  char *s2 = xmalloc(my_strlen(str));

  if(str != NULL){
    for(i = 0 ; *str != '\0' ; i++,str++){
      s2[i] = *str;
    }
    s2[i] = *str;
    return s2;
  }else{
    return NULL;
  }
}
