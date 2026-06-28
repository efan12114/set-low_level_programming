#include <stdlib.h>

/* Assuming the list structure definition */
typedef struct list_s {
    int n;
    struct list_s *next;
} list_t;

/**
 * add_node_end - Adds a new node at the end of a list_t list safely.
 * @head: Pointer to the head of the list.
 * @n: Integer value to be included in the new node.
 *
 * Return: Address of the new element, or NULL if it failed.
 */
list_t *add_node_end(list_t *head, const int n)
{
	list_t *new_node;
	list_t *current = head;

	/* 1. Memory Safety Check */
	new_node = malloc(sizeof(list_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = n;
	new_node->next = NULL;

	/* 2. Empty List Check */
	if (head == NULL)
		return (new_node);

	/* 3. Correct List Traversal Termination */
	while (current->next != NULL)
		current = current->next;

	current->next = new_node;

	return (head);
}
