#include "mylist.h"

/*
 * Pre: Takes a t_node* for the head of the list.
 * Post: Prints every string elem in the list.
 */
void traverse_string(t_node *h)
{
	for (; h != NULL ; h = h->next) {
		my_str(*(char **)h->elem);
		my_char(' ');
	}
}
