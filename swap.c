#include "monty.h"

/**
 * swap - swap element of a stack.
 * @stack: a pointer to the head of stack.
 * @line_number: line number in file.
 *
 * Return: no return.
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *space;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	space = (*stack)->next;
	(*stack)->next = space->next;
	space->next = *stack;
	space->prev = (*stack)->prev;
	(*stack)->prev = space;

	if ((*stack)->next != NULL)
		(*stack)->next->prev = *stack;

	*stack = space;
}
