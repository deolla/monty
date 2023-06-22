#include "monty.h"

/**
 * rotl - rotates the stack to the top..
 * @stack: a pointer to the head of a stake.
 * @line_number: line number in file.
 *
 * Return: no return.
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *last, *second_last;
	(void)line_number;

	if (*stack == NULL || (*stack)->next == NULL)
		return;

	last = *stack;
	while (last->next != NULL)
		last = last->next;

	second_last = last->prev;
	last->prev = NULL;
	last->next = *stack;
	(*stack)->prev = last;
	second_last->next = NULL;
	*stack = last;
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
	stack_t *pop;
	(void)line_number;

	pop = *stack;

	if (*stack == NULL || (*stack)->next == NULL)
		return;

	while (pop->next != NULL)
		pop = pop->next;

	pop->prev->next = NULL;
	pop->prev = NULL;
	pop->next = *stack;
	(*stack)->prev = pop;
	*stack = pop;
}
