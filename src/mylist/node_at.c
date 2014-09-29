#include "mylist.h"

/*
 * Pre: Takes a t_node* for the head and an unsigned int index to get the node at.
 * Post: Returns the t_node at the given index.
 */
t_node *node_at(t_node *h, unsigned int i)
{
	if (h != NULL) {
		for(; i > 0 && h->next != NULL ; i--, h = h->next)
			;
		return h;
	} else
		return NULL;
}
