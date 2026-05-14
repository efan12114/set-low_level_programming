#include "lists.h"

/**
 * free_listint2 - frees a listint_t list and sets the head to NULL
 * @h: double pointer to the head of the list
 */
void free_listint2(listint_t **h)
{
	listint_t *temp;

	if (h == NULL || *h == NULL)
		return;

	while (*h)
	{
		temp = (*h)->next;
		free(*h);
		*h = temp;
	}

	*h = NULL;
}
