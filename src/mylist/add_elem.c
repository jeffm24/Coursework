#include "mylist.h"

/*
 * Pre: Takes a void* for the elem of the node to be added and a t_node** for the head of the list.
 * Post: Creates a new node with the provided elem and adds it to the list.
 */
void add_elem(void *e, t_node **h)
{
	if (e != NULL)
		add_node(new_node(e, NULL), h);
}
