#include "monty.h"

/**
 * f_push - add node to the stack
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */
void f_push(stack_t **head, unsigned int counter)
{
	int n, j = 0, flag = 0;
	stack_t *new_node;

	if (global.arg)
	{
		if (global.arg[0] == '-')
			j++;
		for (; global.arg[j] != '\0'; j++)
		{
			if (global.arg[j] > '9' || global.arg[j] < '0')
				flag = 1;
		}
		if (flag == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", counter);
			fclose(global.file);
			free(global.line);
			free_stack(*head);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", counter);
		fclose(global.file);
		free(global.line);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	n = atoi(global.arg);
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		fclose(global.file);
		free(global.line);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = *head;
	if (*head != NULL)
		(*head)->prev = new_node;
	*head = new_node;
}

/**
 * f_pall - prints the stack
 * @head: stack head
 * @counter: no used
 * Return: no return
 */
void f_pall(stack_t **head, unsigned int counter)
{
	stack_t *h;
	(void)counter;

	h = *head;
	if (h == NULL)
		return;
	while (h != NULL)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}
