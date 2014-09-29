#include "my.h"
#include <stdlib.h>

/*
  Author: Jeff Mariconda
  Class: cs392

  Malloc with error checking to be used for memory allocation.
*/

void *xmalloc(unsigned int n)
{
  void *p;

  if((p = malloc(n)) == NULL){
    my_str("Virtual memory exhausted.\n");
    exit(1);
  }
  return p;
}
