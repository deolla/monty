#include "monty.h"

/**
 * pop - removes top element of stack.
 * @stack: pointer to the head of stack.
 * @line_number: line number in file.
 *
 * Return: no return.
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *space;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	space = *stack;
	*stack = (*stack)->next;

	if (*stack != NULL)
		(*stack)->prev = NULL;

	free(space);
}
