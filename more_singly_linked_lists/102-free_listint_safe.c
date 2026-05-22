#include "lists.h"
#include <stdlib.h>

/**
 * _ra - reallocates memory for an array of pointers to nodes
 * @list: the old array to append to
 * @size: size of the new array
 * @new: new node to add to the array
 *
 * Return: pointer to the new array
 */
listint_t **_ra(listint_t **list, size_t size, listint_t *new)
{
	listint_t **newlist;
	size_t i;

	newlist = malloc(size * sizeof(listint_t *));
	if (!newlist)
	{
		free(list);
		exit(98);
	}
	for (i = 0; i < size - 1; i++)
		newlist[i] = list[i];
	newlist[i] = new;
	free(list);
	return (newlist);
}

/**
 * free_listint_safe - frees a listint_t list safely
 * @h: double pointer to the start of the list
 *
 * Return: the size of the list that was freed
 */
size_t free_listint_safe(listint_t **h)
{
	size_t i, num = 0;
	listint_t **list = NULL;
	listint_t *next;

	if (!h || !*h)
		return (0);

	while (*h)
	{
		for (i = 0; i < num; i++)
		{
			if (*h == list[i])
			{
				*h = NULL;
				free(list);
				return (num);
			}
		}
		num++;
		list = _ra(list, num, *h);
		next = (*h)->next;
		free(*h);
		*h = next;
	}
	free(list);
	return (num);
}
