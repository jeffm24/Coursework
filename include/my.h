#ifndef _MY_H_
#define _MY_H_
#ifndef NULL
#define NULL ((void*)0)
#endif
#include <unistd.h>
#include <stdlib.h>

/*
  Author: Jeff Mariconda
  Class: cs392
  
  Basic library functions for printing/modifying chars, ints, and strings.
*/

//Prints the given char
void my_char(char);

//Prints the given string
void my_str(char*);

//Prints the given int
void my_int(int);

//Prints the given int in the given base
void my_num_base(int, char*);

//Prints every letter from a-z
void my_alpha();

//Prints every digit from 0-9
void my_digits();

//Returs the length of the given string
int my_strlen(char*);

//Reverses the given string and returns it's length
int my_revstr(char*);

//Returns the index of the first instance of the given char in the given string from left to right
int my_strpos(char*, char);

//Returns the index of the first instance of the given char in the given string from right to left 
int my_strrpos(char*, char);

//Copies a literal string and copies it to newly allocated memory
char *my_strdup(char*);

//Compares two strings and returns whether they are equal or one is greater than the other
int my_strcmp(char*, char*);

//Same as my_strcmp but with a contraint on the max number of letters to check for comparing the strings
int my_strncmp(char*, char*, unsigned int);

//Copies string from given src string to the given dst string and returns dst
char *my_strcpy(char*, char*);

//Same as my_strcpy but only copies the first n characters from src
char *my_strncpy(char*, char*, unsigned int);

//Creates a new string that is the concatination of both strings passed to it
char *my_strconcat(char*, char*);

//Creates a new string with the entire s1 and the first n characters of s2
char *my_strnconcat(char*, char*, unsigned int);

//Concatinates s2 to the end of s1
char *my_strcat(char*, char*);

//Finds the first instance of the given char in the given string from left to right and returns a pointer to that char
char *my_strfind(char*, char);

//Finds the first instance of the given char in the given string from right to left and returns a pointer to that char
char *my_strrfind(char*, char);

//Traverses a vector and returns a string contained all of the strings within separated by whitespaces.
char *my_vect2str(char**);

//Takes a string and turns it into a vector using spaces as delimiters.
char **my_str2vect(char*);

//Malloc with error checking
void *xmalloc(unsigned int);

//Takes a string and parses it for an int (taking signs into account) and returns it.
int my_atoi(char*);

#endif
