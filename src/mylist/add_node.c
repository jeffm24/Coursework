#include "mylist.h"

/*
 * Pre: Takes a t_node* for the node to be added and a t_node** for the head of the list.
 * Post: Adds the given node at the head position of the list.
 */
void add_node(t_node *n, t_node **h)
{
	if (n != NULL) {
		if (h != NULL && *h != NULL) {
			n->next = *h;
			*h = n;
		} else if (h != NULL && *h == NULL)
			*h = n;
	}
}
