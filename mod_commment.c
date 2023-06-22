#include "monty.h"

/**
 * mod - computes rest of division of second top element
 * of stack bytop element of stack.
 * @stack: a pointer to the head of stack.
 * @line_number: line number in file.
 *
 * Return: no return.
 */
void mod(stack_t **stack, unsigned int line_number)
{
	int total, divisor;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	divisor = (*stack)->n;

	if (divisor == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	total = (*stack)->next->n % divisor;
	pop(stack, line_number);
	(*stack)->n = total;
}
