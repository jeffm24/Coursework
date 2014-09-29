#include "mylist.h"

/*
 * Pre: Takes a t_node* for the nodes to be appended and a t_node** for the head of the list.
 * Post: Appends the given node to the end of the list.
 */
void append(t_node *n, t_node **h)
{
	t_node *it;

	if(n != NULL){
		if(h != NULL && *h != NULL){
			it = *h;
			for(; it->next != NULL ; it = it->next)
				;
			it->next = n;
		}else
			(*h)->next = n;
	}
}
