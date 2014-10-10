#include "my.h"

/*
 * Author: Jeff Mariconda
 * Class: CS392
 *
 * Pre: Takes a char* string to convert.
 * Post: Returns a vector consisting of the words in the string using spaces as delimiters.
 */
char **my_str2vect(char *s)
{
  char **v;
  int strL;
  int l;
  int i, j, k;

  v = NULL;
  if (s != NULL) {
    //Figure out how many words there are in the string and allocate a vector based on that
    for (i = 0, l = 0 ; s[i] != '\0' ; l++) {
      if (l == 0 && (s[i] == ' ' || s[i] == '\t')) {
	for (; s[i] == ' ' || s[i] == '\t' ; s++)
	  ;
      }
	
      for(; s[i] != ' ' && s[i] != '\t' && s[i] != '\0' ; i++)
	;
      for (; s[i] == ' ' || s[i] == '\t' ; i++)
	;
    }

    v = xmalloc(l * sizeof(char*) + sizeof(char*));
    
    //Figure out the length of each word in the string and allocate the strings in the vector to match
    for (i = 0, j = 0 ; i <= l ; i++) {	
      for (strL = 0 ; s[j] != ' ' && s[j] != '\t' && s[j] != '\0' ; j++, strL++)
	;
      v[i] = xmalloc(strL * sizeof(char) + sizeof(char));
      for (; s[j] == ' ' || s[j] == '\t' ; j++)
	;
    }
    v[i] = NULL;

    //Fill the vector with the words
    for (i = 0, j = 0 ; i <= l ; i++) {
      for (k = 0 ; s[j] != ' ' && s[j] != '\t' && s[j] != '\0' ; j++, k++) {
	v[i][k] = s[j];
      }
      v[i][k++] = '\0';
      for (; s[j] == ' ' || s[j] == '\t' ; j++) 
	;
    }
  }

  return v;
}
