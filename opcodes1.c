#include "monty.h"

/**
 * f_push - add node to the stack
 * @stack: stack head
 * @line_number: line_number
 */
void f_push(stack_t **stack, unsigned int line_number)
{
	int n, j = 0, flag = 0;
	stack_t *new_node;

	if (!global.arg)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		fclose(global.file); free(global.line); free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	if (global.arg[0] == '-')
		j++;
	for (; global.arg[j] != '\0'; j++)
	{
		if (global.arg[j] < '0' || global.arg[j] > '9')
			flag = 1;
	}
	if (flag == 1)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		fclose(global.file); free(global.line); free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	n = atoi(global.arg);
	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		fclose(global.file); free(global.line); free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = *stack;
	if (*stack)
		(*stack)->prev = new_node;
	*stack = new_node;
}

/**
 * f_pall - prints the stack
 * @stack: stack head
 * @line_number: no used
 */
void f_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	(void)line_number;

	tmp = *stack;
	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * f_pint - prints the top
 * @stack: stack head
 * @line_number: line_number
 */
void f_pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		fclose(global.file); free(global.line); free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * f_pop - prints the top
 * @stack: stack head
 * @line_number: line_number
 */
void f_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		fclose(global.file); free(global.line); free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	*stack = tmp->next;
	if (*stack)
		(*stack)->prev = NULL;
	free(tmp);
}

/**
 * f_swap - adds the top two elements of the stack.
 * @stack: stack head
 * @line_number: line_number
 */
void f_swap(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		fclose(global.file); free(global.line); free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}
