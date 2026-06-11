#include "monty.h"

/**
 * f_add - adds the top two elements of the stack.
 * @stack: stack head
 * @line_number: line_number
 */
void f_add(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	int len = 0, aux;

	tmp = *stack;
	while (tmp)
	{
		tmp = tmp->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		fclose(global.file); free(global.line); free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	aux = tmp->n + tmp->next->n;
	tmp->next->n = aux;
	*stack = tmp->next;
	(*stack)->prev = NULL;
	free(tmp);
}

/**
 * f_nop - nothing
 * @stack: stack head
 * @line_number: line_number
 */
void f_nop(stack_t **stack, unsigned int line_number)
{
	(void) line_number;
	(void) stack;
}

/**
 * f_div - divides the top two elements of the stack.
 * @stack: stack head
 * @line_number: line_number
 */
void f_div(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	int len = 0, aux;

	tmp = *stack;
	while (tmp)
	{
		tmp = tmp->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		fclose(global.file); free(global.line); free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	if (tmp->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		fclose(global.file); free(global.line); free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	aux = tmp->next->n / tmp->n;
	tmp->next->n = aux;
	*stack = tmp->next;
	(*stack)->prev = NULL;
	free(tmp);
}

/**
 * f_mul - multiplies the top two elements of the stack.
 * @stack: stack head
 * @line_number: line_number
 */
void f_mul(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	int len = 0, aux;

	tmp = *stack;
	while (tmp)
	{
		tmp = tmp->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		fclose(global.file); free(global.line); free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	aux = tmp->next->n * tmp->n;
	tmp->next->n = aux;
	*stack = tmp->next;
	(*stack)->prev = NULL;
	free(tmp);
}
