#include <stdlib.h>
#include <stdio.h>
#include "lists.h"

int main(void)
{
	listint_t *head;
	listint_t hello = {8, NULL};
	listint_t *new;

	head = &hello;
	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (1);
	new->n = 9;
	new->next = head;
	head = new;

	print_listint(head);
	free(new);
	return (0);
}
