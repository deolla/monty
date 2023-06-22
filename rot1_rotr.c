#include "monty.h"

/**
 * rotl - rotates the stack to the top..
 * @stack: a pointer to the head of a stake.
 * @line_number: line number in file.
 *
 * Return: no return.
 */
void rotl(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *current, *last;

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

/**
 * rotr - rotates the stack to the bottom.
 * @stack: a pointer to the head of a stack.
 * @line_number: line number in file.
 *
 * Return: no return.
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *last, *second_last;

	(void)line_number;

	if (*stack == NULL || (*stack)->next == NULL)
		return;

	last = *stack;
	while (last->next != NULL)
		last = last->next;

	second_last = last->prev;
	second_last->next = NULL;
	last->prev = NULL;
	last->next = *stack;
	(*stack)->prev = last;
	*stack = last;
}
