#include "monty.h"

/**
 * sub - subtracts top element of stack from second top element of stack.
 * @stack: a pointer to the head of the stack.
 * @line_number: line number of file.
 *
 * Return: no return.
 */
void sub(stack_t **stack, unsigned int line_number)
{
	int total;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	total = (*stack)->next->n - (*stack)->n;
	pop(stack, line_number);
	(*stack)->n = total;
}
	
