#include "mylist.h"

/*
 * Pre: Takes a t_node* for the head of the list.
 * Post: Returns the length of the list.
 */
unsigned int count_nodes(t_node *h)
{
	unsigned int i;

	if(h != NULL){
		for(i = 0 ; h != NULL ; i++, h = h->next)
			;
	}
	return i;
}
