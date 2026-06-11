#include "monty.h"

/**
 * execute_instruction - executes the opcode
 * @opcode: opcode to execute
 * @stack: head linked list - stack
 * @line_number: line_counter
 * Return: no return
 */
void execute_instruction(char *opcode, stack_t **stack, unsigned int line_number)
{
	instruction_t opst[] = {
		{"push", f_push}, {"pall", f_pall}, {"pint", f_pint},
		{"pop", f_pop}, {"swap", f_swap}, {"add", f_add},
		{"nop", f_nop}, {"div", f_div}, {"mul", f_mul},
		{NULL, NULL}
	};
	unsigned int i = 0;

	while (opst[i].opcode && opcode)
	{
		if (strcmp(opcode, opst[i].opcode) == 0)
		{
			opst[i].f(stack, line_number);
			return;
		}
		i++;
	}
	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
	fclose(global.file);
	free(global.line);
	free_stack(*stack);
	exit(EXIT_FAILURE);
}

/**
 * free_stack - frees a doubly linked list
 * @stack: head of the stack
 */
void free_stack(stack_t *stack)
{
	stack_t *temp;

	while (stack)
	{
		temp = stack->next;
		free(stack);
		stack = temp;
	}
}
