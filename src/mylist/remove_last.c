#include "mylist.h"

/*
 * Pre: Takes a t_node** for the head of the list.
 * Post: Removes the last node in the list and returns the elem of that node.
 */
void *remove_last(t_node **h)
{
	t_node *it, *rem;
	void *e;
	
	if (h != NULL && *h != NULL) {
		if ((*h)->next != NULL) {
			it = *h;
			for(; it->next->next != NULL ; it = it->next)
				;
			rem = it->next;
			e = rem->elem;
			it->next = NULL;
			free(rem);
		} else {
			e = (*h)->elem;
			free(*h);
		}
		return e;
	} else 
		return NULL;
}
