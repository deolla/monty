#include "monty.h"

/**
 * add - adds the top two elements of the stack.
 * @stack: a pointer to the head of stack.
 * @line_number: line number in file.
 *
 * Return: no return.
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *space;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n += (*stack)->n;
	space = *stack;
	*stack = (*stack)->next;

	if (*stack != NULL)
		(*stack)->prev = NULL;

	free(space);
}
