#include "my.h"

/*
  Author: Jeff Mariconda
  Class: cs392

  pre: takes an int to be represented and a string containing the characters that make up the base
  post: prints the given int in that given base to stdout
*/

void my_num_base(int num, char* s)
{
  int b, rem, i, j;
  long int n = num, temp;

  if((b = my_strlen(s)) > 0){
    
    if(n < 0){
      my_char('-');
      n *= -1;
    }
    temp = n;
    
    if(b != 0 && b != 1){
      for(i = 0 ; temp > 0 ; i++,temp /= b);

      for(temp = n ; i != 0 ; temp = n, i--){
	for(j = 0 ; j < i ; rem = temp % b, temp /= b, j++);
	my_char(s[rem]);
      }
    }else if(b == 1){
      for(i = 0;i < temp;i++)
	my_char(s[0]);
    }else
      my_str("Base not valid.");
  }else if(n == 0){
    my_int(0);
  }else{
    my_str("Base not valid.");
  }
}
