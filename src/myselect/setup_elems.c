#include "myselect.h"
/*
 * Author: Jeff Mariconda
 * Class: CS-392
 *
 * Pre: Takes an int number of elems and a char** of the element names
 * Post: Performs the initial setup of the elements array
 */
void setup_elems(int n, char **elems) 
{
  int i;
  
  gl_env.pos = 0;
  gl_env.nbelems = n;
  gl_env.elements = xmalloc(n * sizeof(t_elem));
  for (i = 0 ; i < n ; i++) {
    gl_env.elements[i].elem = elems[i];
    gl_env.elements[i].size = my_strlen(elems[i]);
    gl_env.elements[i].mode = 0;
  }
}
