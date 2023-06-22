#include "monty.h"

/**
 * pint - prints the value at the top of stack.
 * @stack: pointer to the head of the stack.
 * @line_number: line number in file.
 *
 * Return: no return.
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
