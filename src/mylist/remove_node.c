#include "mylist.h"

/*
 * Pre: Takes a t_node** for the head of the list.
 * Post: Removes the first node in the list and returns its elem.
 */
void *remove_node(t_node **h)
{
	t_node *rem;
	void *e;
  
	if (h != NULL && *h != NULL) {
		e = (*h)->elem;
		rem = *h;
		*h = (*h)->next;
		free(rem);
		return e;
	}else
		return NULL;
} 
