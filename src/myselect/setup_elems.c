#inlcude "myselect.h"
/*
 * Author: Jeff Mariconda
 * Class: CS-392
 *
 * Pre: Takes an int number of elems and a char** of the element names
 * Post: Performs the initial setup of the elements array
 */
void setup_elems(int n, char **elems) 
{
  gl_env.pos = 0;
  gl_env.nbelems = n;
  gl_env.elements = xmalloc(n * sizeof(t_elem));
  for (i = 0 ; i < n ; i++) {
    gl_env.elements[0].elem = elems[i];
    gl_env.elements[0].size = my_strlen(argv[i]);
    gl_env.elements[0].mode = 0;
  }
}
