#include "my.h"

/*
 * Author: Jeff Mariconda
 * Class: CS392
 * 
 * 
 */
int main() 
{
  int i;
  char *str = "       \t This  \t    is     \t  a    \t  test    of   \t     some       stuff.    \t  \t       ";
  char **v = my_str2vect(str);
  
  for (i = 0 ; v[i] != NULL ; i++) {
    my_int(i);
    my_str(": -->");
    my_str(v[i]);
    my_str("<--\n");
  }
  
  my_str("-->");
  my_str(my_vect2str(v));
  my_str("<--\n");

  return 0;
}
