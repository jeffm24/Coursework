#include "mylist.h"

/*
 * Pre: Takes a void* for the elem of the new node and a t_node* for the next t_node.
 * Post: Allocates a new node with these values and returns it.
 */
t_node *new_node(void *e, t_node *n){
	t_node *node = NULL;

	if(e != NULL){
		node = xmalloc(sizeof(t_node));
		node->elem = e;
		node->next = n; 
	}
	return node;
}
