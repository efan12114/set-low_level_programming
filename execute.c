#include "monty.h"
int execute(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
	instruction_t opst[] = {
		{"push", f_push}, {"pall", f_pall}, {"pint", f_pint},
		{NULL, NULL}
	};
	unsigned int i = 0;
	char *op;

	op = strtok(content, " \n\t\r");
	if (op == NULL || op[0] == '#')
		return (0);
	bus.arg = strtok(NULL, " \n\t\r");
	while (opst[i].opcode && op)
	{
		if (strcmp(op, opst[i].opcode) == 0)
		{
			opst[i].f(stack, counter);
			return (0);
		}
		i++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", counter, op);
	fclose(file);
	free(content);
	free_stack(*stack);
	exit(EXIT_FAILURE);
}
