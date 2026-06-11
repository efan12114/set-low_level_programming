#include "monty.h"

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node, *tmp;
	(void)line_number;

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = shared_arg;

	if (data_mode == 0)
	{
		new_node->prev = NULL;
		new_node->next = *stack;
		if (*stack)
			(*stack)->prev = new_node;
		*stack = new_node;
	}
	else
	{
		new_node->next = NULL;
		if (!*stack)
		{
			new_node->prev = NULL;
			*stack = new_node;
		}
		else
		{
			tmp = *stack;
			while (tmp->next)
				tmp = tmp->next;
			tmp->next = new_node;
			new_node->prev = tmp;
		}
	}
}

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	(void)line_number;
	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

void pint(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	if (!stack || !*stack)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	*stack = tmp->next;
	if (*stack)
		(*stack)->prev = NULL;
	free(tmp);
}

void swap(stack_t **stack, unsigned int line_number)
{
	int temp;
	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}

void add(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n += (*stack)->n;
	pop(stack, line_number);
}

void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

void sub(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n -= (*stack)->n;
	pop(stack, line_number);
}

void div_op(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n /= (*stack)->n;
	pop(stack, line_number);
}

void mul(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n *= (*stack)->n;
	pop(stack, line_number);
}

void mod(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n %= (*stack)->n;
	pop(stack, line_number);
}

void pchar(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*stack)->n);
}

void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	(void)line_number;

	while (tmp && tmp->n > 0 && tmp->n <= 127)
	{
		printf("%c", tmp->n);
		tmp = tmp->next;
	}
	printf("\n");
}

void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *tail;
	(void)line_number;

	if (!stack || !*stack || !(*stack)->next)
		return;

	top = *stack;
	tail = *stack;
	while (tail->next)
		tail = tail->next;

	*stack = top->next;
	(*stack)->prev = NULL;
	tail->next = top;
	top->prev = tail;
	top->next = NULL;
}

void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *tail;
	(void)line_number;

	if (!stack || !*stack || !(*stack)->next)
		return;

	tail = *stack;
	while (tail->next)
		tail = tail->next;

	tail->prev->next = NULL;
	tail->next = *stack;
	tail->prev = NULL;
	(*stack)->prev = tail;
	*stack = tail;
}

void set_stack(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	data_mode = 0;
}

void set_queue(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	data_mode = 1;
}
