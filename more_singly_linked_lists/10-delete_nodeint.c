#include "lists.h"
#include <stdlib.h>

/**
 * delete_nodeint_at_index - deletes the node at a given index
 * @head: double pointer to the head of the list
 * @index: index of the node that should be deleted, starting at 0
 *
 * Return: 1 if it succeeded, -1 if it failed
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *tmp, *prev;
	unsigned int i = 0;

	if (!head || !*head)
		return (-1);

	tmp = *head;

	if (index == 0)
	{
		*head = tmp->next;
		free(tmp);
		return (1);
	}

	while (tmp && i < index)
	{
		prev = tmp;
		tmp = tmp->next;
		i++;
	}

	if (!tmp)
		return (-1);

	prev->next = tmp->next;
	free(tmp);

	return (1);
}
