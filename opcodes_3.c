#include "monty.h"

/**
 * f_pstr - prints the string starting at the top of the stack
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */
void f_pstr(stack_t **head, unsigned int counter)
{
	stack_t *h;
	(void)counter;

	h = *head;
	while (h)
	{
		if (h->n <= 0 || h->n > 127)
			break;
		printf("%c", h->n);
		h = h->next;
	}
	printf("\n");
}

/**
 * f_rotl - rotates the stack to the top
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */
void f_rotl(stack_t **head, unsigned int counter)
{
	stack_t *tmp = *head, *aux;
	(void)counter;

	if (*head == NULL || (*head)->next == NULL)
		return;

	aux = (*head)->next;
	aux->prev = NULL;
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *head;
	(*head)->next = NULL;
	(*head)->prev = tmp;
	*head = aux;
}

/**
 * f_rotr - rotates the stack to the bottom
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */
void f_rotr(stack_t **head, unsigned int counter)
{
	stack_t *copy;
	(void)counter;

	copy = *head;
	if (*head == NULL || (*head)->next == NULL)
		return;

	while (copy->next)
		copy = copy->next;

	copy->next = *head;
	copy->prev->next = NULL;
	copy->prev = NULL;
	(*head)->prev = copy;
	*head = copy;
}

/**
 * f_stack - sets format to stack (LIFO)
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */
void f_stack(stack_t **head, unsigned int counter)
{
	(void)head;
	(void)counter;
	global.lifi = 0;
}

/**
 * f_queue - sets format to queue (FIFO)
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */
void f_queue(stack_t **head, unsigned int counter)
{
	(void)head;
	(void)counter;
	global.lifi = 1;
}
#include "monty.h"

/**
 * f_pstr - prints the string starting at the top of the stack
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */
void f_pstr(stack_t **head, unsigned int counter)
{
	stack_t *h;
	(void)counter;

	h = *head;
	while (h)
	{
		if (h->n <= 0 || h->n > 127)
			break;
		printf("%c", h->n);
		h = h->next;
	}
	printf("\n");
}

/**
 * f_rotl - rotates the stack to the top
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */
void f_rotl(stack_t **head, unsigned int counter)
{
	stack_t *tmp = *head, *aux;
	(void)counter;

	if (*head == NULL || (*head)->next == NULL)
		return;

	aux = (*head)->next;
	aux->prev = NULL;
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *head;
	(*head)->next = NULL;
	(*head)->prev = tmp;
	*head = aux;
}

/**
 * f_rotr - rotates the stack to the bottom
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */
void f_rotr(stack_t **head, unsigned int counter)
{
	stack_t *copy;
	(void)counter;

	copy = *head;
	if (*head == NULL || (*head)->next == NULL)
		return;

	while (copy->next)
		copy = copy->next;

	copy->next = *head;
	copy->prev->next = NULL;
	copy->prev = NULL;
	(*head)->prev = copy;
	*head = copy;
}
