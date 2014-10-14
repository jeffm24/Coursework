#include "my.h"

/*
 * Author: Jeff Mariconda
 * Class: CS 392
 *
 * Pre: Takes a char** vector.
 * Post: Frees all strings within the vector and then frees the vector.
 */
void my_freevect(char **v)
{
  int i;

  for (i = 0 ; v[i] != NULL ; i++)
    free(v[i]);

  free(v);      
}
