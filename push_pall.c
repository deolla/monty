#include "monty.h"

/**
 * push - insert element into the stack.
 * @stack: pointer to the head of the stack.
 * @line_number: line number in file.
 *
 * Return: no return.
 */
void push(stack_t **stack, unsigned int line_number)
{
	char *arg;
	int m;

	arg = strtok(NULL, " \n");

	if (arg == NULL || !is_number(arg))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	m = atoi(arg);
	push_stack(stack, m);
}


/**
 * pall - prints all values in the stack.
 * @stack: pointer to the head of stack.
 * @line_number: line number in file.
 *
 * Return: no return.
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current;
	(void)line_number;

	current = *stack;
	if (current == NULL)
		return;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
