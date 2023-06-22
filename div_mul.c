#include "monty.h"

/**
 * div_op - divides second top element of stack by top element of stack.
 * @stack: a pointer to the head of the stack.
 * @line_number: line number in file.
 *
 * Return: no return.
 */
void div_op(stack_t **stack, unsigned int line_number)
{
	int total;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	total = (*stack)->next->n / (*stack)->n;
	pop(stack, line_number);
	(*stack)->n = total;
}

/**
 * mul - multiplies second top element of stack with top element of stack.
 * @stack: a pointer to the head of stack.
 * @line_number: line number in the file.
 *
 * Return: no return.
 */
void mul(stack_t **stack, unsigned int line_number)
{
	int total;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	total = (*stack)->next->n * (*stack)->n;
	pop(stack, line_number);
	(*stack)->n = total;
}
