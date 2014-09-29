#include "mylist.h"

/*
 * Pre: Takes a t_node** for the head of the list and an unsigned int index to remove the node at.
 * Post: Removes the node at the given index and returns its elem.
 */
void *remove_node_at(t_node **h, unsigned int i)
{
	t_node *it, *prev, *rem;
	void *e;
  
	if (h != NULL && *h != NULL) {
		if (i != 0) {
			for (prev = *h, it = prev->next ; i > 1 && it->next != NULL; i--, prev = prev->next, it = it->next)
				;
			e = it->elem;
			rem = it;
			it = it->next;
			prev->next = it;			
			free(rem);
			return e;
		} else
			remove_node(h);
	} else
		return NULL;
}
