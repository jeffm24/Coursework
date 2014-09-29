#include "my.h"

/*
  Author: Jeff Mariconda
  Class: cs392

  pre: takes an int (positive or negative)
  post: prints the int to stdout
*/

void my_int(int n){
  int l, mod;
  long int num = n, temp;

  if(num < 0){
    my_char('-');
    num *= -1;
  }

  //get length of int and max mod amount
  for(l = 1,temp = num,mod = 1 ; temp >= 10 ; temp /= 10,mod *= 10,l++);
  
  //while the length is not 0, print out the left-most digit and pop it off the int
  for(temp = num ; l > 0 ; num %= mod,temp = num,mod /= 10,l--){
    temp /= mod;
    my_char(temp + '0');
  }
}
