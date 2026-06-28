#include "monty.h"

/**
 * execute_instruction - executes the opcode
 * @opcode: opcode to execute
 * @stack: head of the stack
 * @line_number: line number
 * Return: 0 on success, 1 otherwise
 */
int execute_instruction(char *opcode, stack_t **stack, unsigned int line_number)
{
	instruction_t opst[] = {
		{"push", f_push},
		{"pall", f_pall},
		{"pint", f_pint},
		{"pop", f_pop},
		{"swap", f_swap},
		{"add", f_add},
		{"nop", f_nop},
		{"sub", f_sub},
		{"div", f_div},
		{"mul", f_mul},
		{"mod", f_mod},
		{"pchar", f_pchar},
		{"pstr", f_pstr},
		{NULL, NULL}
	};
	unsigned int i = 0;

	while (opst[i].opcode && opcode)
	{
		if (strcmp(opst[i].opcode, opcode) == 0)
		{
			opst[i].f(stack, line_number);
			return (0);
		}
		i++;
	}
	if (opcode && opst[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
		fclose(global.file);
		free(global.line);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	return (1);
}
#include "monty.h"

/**
 * execute_instruction - executes the opcode
 * @opcode: opcode to execute
 * @stack: head of the stack
 * @line_number: line number
 * Return: 0 on success, 1 otherwise
 */
int execute_instruction(char *opcode, stack_t **stack, unsigned int line_number)
{
	instruction_t opst[] = {
		{"push", f_push},
		{"pall", f_pall},
		{"pint", f_pint},
		{"pop", f_pop},
		{"swap", f_swap},
		{"add", f_add},
		{"nop", f_nop},
		{"sub", f_sub},
		{"div", f_div},
		{"mul", f_mul},
		{"mod", f_mod},
		{"pchar", f_pchar},
		{"pstr", f_pstr},
		{"rotl", f_rotl},
		{"rotr", f_rotr},
		{NULL, NULL}
	};
	unsigned int i = 0;

	while (opst[i].opcode && opcode)
	{
		if (strcmp(opst[i].opcode, opcode) == 0)
		{
			opst[i].f(stack, line_number);
			return (0);
		}
		i++;
	}
	if (opcode && opst[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
		fclose(global.file);
		free(global.line);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	return (1);
}
