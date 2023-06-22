#include "monty.h"

/**
 * execute_command - execute instructions.
 * @opcode: opcode.
 * @stack: a pointer to the head of the stack
 * @line_number: line number in file.
 *
 * Return: no return.
 */
void execute_command(char *opcode, stack_t **stack, unsigned int line_number)
{
	int i, p;

	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
	};

	p = sizeof(instructions) / sizeof(instruction_t);

	for (i = 0; i < p; i++)
	{
		if (strcmp(opcode, instructions[i].opcode) == 0)
		{
			instructions[i].f(stack, line_number);
			break;
		}
	}
	if  (i == p)
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
		exit(EXIT_FAILURE);
	}
}

/**
 * process_file - execute instructions.
 * @filename: file name.
 *
 * Return: no return.
 */
void process_file(const char *filename)
{
	char *line = NULL, *opcode;
	size_t line_size = 0;
	ssize_t line_length;
	unsigned int line_number = 0;
	stack_t *stack = NULL;
	FILE *file = fopen(filename, "r");

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		free(line);
		exit(EXIT_FAILURE);
	}

	while ((line_length = getline(&line, &line_size, file)) != -1)
	{
		line_number++;
		opcode = strtok(line, " \n\t\r");

		if (opcode == NULL)
			continue;

		execute_command(opcode, &stack, line_number);
	}
	fclose(file);
	free(line);

	while (stack != NULL)
	{
		stack_t *next = stack->next;

		free(stack);
		stack = next;
	}

}
