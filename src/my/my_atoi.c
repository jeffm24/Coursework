#include "my.h"

/*
 * Author: Jeff Mariconda
 * Class: CS-392
 *
 * Pre: Takes a char* to parse.
 * Post: Parses the string for an int taking into account any signs and returns it.
 */
int my_atoi(char* s)
{
  int ret;
  int sign;

  for (; *s == ' ' ; s++)
    ;
  for (ret = 0, sign = 1 ; *s != '\0' ; s++) {
    if (*s == ' ' || *s == '.')
      break;
    else if (*s == '-')
      sign *= -1;
    else if (*s >= '0' && *s <= '9') {
      if (ret > 0)
	ret *= 10;
      ret += *s - '0';
    }
  }

  return ret * sign;
}
