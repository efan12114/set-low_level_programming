#include "monty.h"

int shared_arg = 0;
int data_mode = 0;

int main(int argc, char **argv)
{
	FILE *file;
	char *line = NULL, *opcode;
	size_t len = 0;
	unsigned int line_number = 1;
	stack_t *stack = NULL;
	stack_t *temp;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&line, &len, file) != -1)
	{
		opcode = strtok(line, " \n\t\r");
		if (opcode && opcode[0] != '#')
		{
			if (strcmp(opcode, "push") == 0)
			{
				char *arg = strtok(NULL, " \n\t\r");
				if (!arg)
				{
					fprintf(stderr, "L%u: usage: push integer\n", line_number);
					exit(EXIT_FAILURE);
				}
				shared_arg = atoi(arg);
				push(&stack, line_number);
			}
			else if (strcmp(opcode, "pall") == 0)
				pall(&stack, line_number);
			else if (strcmp(opcode, "pint") == 0)
				pint(&stack, line_number);
			else if (strcmp(opcode, "pop") == 0)
				pop(&stack, line_number);
			else if (strcmp(opcode, "swap") == 0)
				swap(&stack, line_number);
			else if (strcmp(opcode, "add") == 0)
				add(&stack, line_number);
			else if (strcmp(opcode, "nop") == 0)
				nop(&stack, line_number);
			else if (strcmp(opcode, "sub") == 0)
				sub(&stack, line_number);
			else if (strcmp(opcode, "div") == 0)
				div_op(&stack, line_number);
			else if (strcmp(opcode, "mul") == 0)
				mul(&stack, line_number);
			else if (strcmp(opcode, "mod") == 0)
				mod(&stack, line_number);
			else if (strcmp(opcode, "pchar") == 0)
				pchar(&stack, line_number);
			else if (strcmp(opcode, "pstr") == 0)
				pstr(&stack, line_number);
			else if (strcmp(opcode, "rotl") == 0)
				rotl(&stack, line_number);
			else if (strcmp(opcode, "rotr") == 0)
				rotr(&stack, line_number);
			else if (strcmp(opcode, "stack") == 0)
				set_stack(&stack, line_number);
			else if (strcmp(opcode, "queue") == 0)
				set_queue(&stack, line_number);
		}
		line_number++;
	}
	while (stack)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
	free(line);
	fclose(file);
	return (0);
}
