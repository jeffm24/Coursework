#include "my.h"

/*
Author: Jeff Mariconda
Class: cs392

Test Main for first assignment.
*/

int main()
{
  int i = ~(1 << (8 * sizeof(int) - 1));
  char str[] = "Hello";
  char* str2 = "Hello2";
  char s3[] = "This is a test.";
  char *s4 = "This is also a test.";

  /*
  ------------------------------------------
  Testing for my_char(char)
  ------------------------------------------
  */
  my_str("my_char() Testing:\n");

  my_char('A');            //should print 'A' to the screen (positive case)
 
  my_str("\n\n");
  /*
  ------------------------------------------
  Testing for my_str(char*)
  ------------------------------------------
  */
  my_str("my_str() Testing:\n");

  my_str(str);             //should print the string "Hello" to the screen (positive case)
  my_char('\n'); 
  my_str(str2);            //should print the string "Hello2" to the screen (positive case)
  my_char('\n'); 
  my_str("");              //should print nothing to the screen
  my_char('\n');
  my_str(NULL);            //should print nothing to the screen (negative case)
  
  my_str("\n\n");
  /*
  ------------------------------------------
  Testing for my_int(int)
  ------------------------------------------
  */
  my_str("my_int() Testing:\n");

  my_int(0);               //should print 0
  my_char('\n');
  my_int(7);               //should print 7
  my_char('\n');
  my_int(123);             //should print 123
  my_char('\n');
  my_int(-546);            //should print -546
  my_char('\n');
  my_int(100);             //should print 100
  my_char('\n');
  my_int(i);               //should print the max positive int
  my_char('\n');
  my_int(i + 1);           //should print the max negative int

  my_str("\n\n");
  /*
  ------------------------------------------
  Testing for my_num_base(int, char*)
  ------------------------------------------
  */
  my_str("my_num_base() Testing:\n");

  my_num_base(9, "01");    //should print 1001 (positive case)
  my_char('\n');
  my_num_base(7, "!?#");   //should print #? (positive case)
  my_char('\n');
  my_num_base(5, "");      //should print "Base not valid" (negative case)
  my_char('\n');  
  my_num_base(5, NULL);    //should print "Base not valid" (negative case)
  my_char('\n');
  my_num_base(0, "$");     //should print 0
  my_char('\n');
  my_num_base(-4, "$");    //should print -$$$$
  my_char('\n');
  my_num_base(-7, "01");   //should print -111
 
  my_str("\n\n");
  /*
  ------------------------------------------
  Testing for my_alpha() and my_digits()
  ------------------------------------------
  */
  my_str("my_alpha() and my_digits() Testing:\n");

  my_alpha();              //should print every letter in the alphabet from a-z
  my_char('\n');
  my_digits();             //should print every digit from 0-9

  my_str("\n\n");
  /*
  ------------------------------------------
  Testing for my_strlen(char*)
  ------------------------------------------
  */
  my_str("my_strlen() Testing:\n");

  my_int(my_strlen(str));          //should print 5 (positive case)
  my_char('\n');
  my_int(my_strlen(str2));         //should print 6 (positive case)
  my_char('\n');
  my_int(my_strlen(""));           //should print 0 (negative case)
  my_char('\n');
  my_int(my_strlen(NULL));         //should print -1 (negative)

  my_str("\n\n");
  /*
  ------------------------------------------
  Testing for my_revstr(char*)
  ------------------------------------------
  */
  my_str("my_revstr() Testing:\n");

  my_int(my_revstr(str));          //should print 5 
  my_char('\n');
  my_str(str);                     //should print "olleh"
  my_char('\n');
  my_revstr(NULL);                 //should print nothing
  my_char('\n');
  my_revstr("");                   //should print nothing

  my_str("\n\n");
  /*
  ------------------------------------------
  Testing for my_strpos(char*, char)
  ------------------------------------------
  */
  my_str("my_strpos() Testing:\n");

  my_int(my_strpos(s3, 'a'));               //should print 8 
  my_char('\n');
  my_int(my_strpos(s4, 'o'));               //should print 11
  my_char('\n');
  my_int(my_strpos(s3, 'A'));               //should print -1
  my_char('\n');
  my_int(my_strpos(NULL, 'a'));             //should print -1
  my_char('\n');
  my_int(my_strpos("", 'e'));               //should print -1
  my_char('\n');
  my_int(my_strpos(NULL, 5));               //should print -1

  my_str("\n\n");
  /*
  ------------------------------------------
  Testing for my_strrpos(char*, char)
  ------------------------------------------
  */
  my_str("my_strrpos() Testing:\n");
  
  my_int(my_strrpos(s3, 'a'));               //should print 6 
  my_char('\n');
  my_int(my_strrpos(s4, 'o'));               //should print 8 
  my_char('\n');
  my_int(my_strrpos(NULL, 'a'));             //should print -1 
  my_char('\n');
  my_int(my_strrpos("", 'a'));               //should print -1
  my_char('\n');
  my_int(my_strrpos("hello", 'w'));
  
  my_str("\n\n");
  
  return 0;
}
