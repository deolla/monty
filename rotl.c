#include "monty.h"

/**
 * rotl - rotates the stack to the top.
 * @stack: pointer to the head of the stack.
 * @line_number: line number in file.
 *
 * Return: no return.
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *current, *last;

	(void)line_number;

	if (*stack == NULL || (*stack)->next == NULL)
		return;

	current = *stack;
	last = *stack;

	while (last->next != NULL)
		last = last->next;

	*stack = current->next;
	(*stack)->prev = NULL;

	current->next = NULL;
	current->prev = last;
	last->next = current;
}
