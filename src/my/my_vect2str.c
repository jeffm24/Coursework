#include "my.h"

/*
 * Author: Jeff Mariconda
 * Class: CS392
 *
 * Pre: Takes a char** vector.
 * Post: Returns a string containing all of the strings in the vector separated by whitespaces.
 */
char *my_vect2str(char **v)
{
  unsigned int s, s2, i;
  char *str = NULL;
  
  if (v != NULL && *v != NULL) {
    for (s = 0, i = 0 ; v[i] != NULL ; s += (my_strlen(v[i]) + 1), i++)
      ;
    str = xmalloc(s);

    for (i = 0, s2 = 0 ; v[i] != NULL ; i++) {
      s2 += my_strlen(v[i]);
      my_strcat(str, v[i]);
      if (s2 != s - 1) {
	str[s2] = ' ';
	str[++s2] = '\0';
      }
    }
  }
  return str;
}
