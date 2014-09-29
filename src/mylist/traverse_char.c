#include "mylist.h"

/*
 * Pre: Takes a t_node* for the head of the list.
 * Post: Prints all char elems in the list.
 */
void traverse_char(t_node *h)
{
	for (; h != NULL ; h = h->next) {
		my_char(*(char *)h->elem);
		my_char(' ');
	}
}
