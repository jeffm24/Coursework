#ifndef _MY_LIST_H_
#define _MY_LIST_H_
#include "my.h"

/*
 * Author: Jeff Mariconda
 * Class: CS392
 *
 * Library of methods for a basic linked list.
 */

typedef struct s_node
{
  void *elem;
  struct s_node *next;
}t_node;

//Allocate a new t_node and return it
t_node *new_node(void*, t_node*);

//Adds the given node to the head of the list
void add_node(t_node*, t_node**);

//Creates a new node with the given elem and adds it to the head of the list
void add_elem(void*, t_node**);

//Appends the given node to the end of the list
void append(t_node*, t_node**);

//Adds the given node at the given index
void add_node_at(t_node*, t_node**, unsigned int);

//Removes the first node and returns its elem
void *remove_node(t_node**);

//Removes the node at the given index and returns its elem
void *remove_node_at(t_node**, unsigned int);

//Removes the last node in the list and returns its elem
void *remove_last(t_node**);

//Returns the number of nodes in the list
unsigned int count_nodes(t_node*);

//Removes and frees all nodes in the list
void empty_list(t_node**);

//Returns a pointer to the node at the given index
t_node *node_at(t_node*, unsigned int);

//Returns a pointer to the elem of the node at the given index
void *elem_at(t_node*, unsigned int);

//Prints all of the ints in your list separated by white space
void traverse_int(t_node*);

//Prints all of the chars in your list separated by white space
void traverse_char(t_node*);

//Prints all of the strings in your list separated by white space
void traverse_string(t_node*);
 
#endif
