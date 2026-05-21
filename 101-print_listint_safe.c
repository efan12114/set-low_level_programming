#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

size_t print_listint_safe(const listint_t *head)
{
    size_t count = 0, i;
    const listint_t **list = NULL;
    const listint_t **new_list;

    while (head != NULL)
    {
        for (i = 0; i < count; i++)
        {
            if (head == list[i])
            {
                printf("-> [%p] %d\n", (void *)head, head->n);
                free(list);
                return (count);
            }
        }
        count++;
        new_list = malloc(count * sizeof(listint_t *));
        if (new_list == NULL)
        {
            free(list);
            exit(98);
        }
        for (i = 0; i < count - 1; i++)
            new_list[i] = list[i];
        new_list[i] = head;
        free(list);
        list = new_list;
        printf("[%p] %d\n", (void *)head, head->n);
        head = head->next;
    }
    free(list);
    return (count);
}
