#include "mylist.h"

/*
 * Pre: Takes a t_node* for the head of the list.
 * Post: Prints all int elems in the list.
 */
void traverse_int(t_node *h)
{
	for (; h != NULL ; h = h->next) {
		my_int(*(int *)h->elem);
		my_char(' ');
	}
}
