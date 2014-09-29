#include "mylist.h"

/*
 * Pre: Takes a t_node* to add, a t_node** for the head of the list, and an unsigned int index to 
 *      add the node at.
 * Post: Adds the node at the spcified index in the list.
 */
void add_node_at(t_node *n, t_node **h, unsigned int i)
{
	t_node *it;

	if (n != NULL) {
		if (h != NULL && *h != NULL) {
			if (i != 0) {
				it = *h;
				for (; i > 1 && it->next != NULL ; i--, it = it->next)
					;
				n->next = it->next;
				it->next = n;
			} else {
				n->next = *h;
				*h = n;
			}
		} else
			*h = n;
	}
}
