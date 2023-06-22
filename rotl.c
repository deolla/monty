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
	stack_t *first, *second, *last;

	(void)line_number;

	if (*stack == NULL || (*stack)->next == NULL)
		return;

	first = *stack;
	second = (*stack)->next;
	last = *stack;

	while (last->next != NULL)
		last = last->next;

	*stack = second;
	second->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
}
