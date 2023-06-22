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
	stack_t *space = *stack, *pop;
	(void)line_number;
	
	if(*stack == NULL || (*stack)->next == NULL)
		return;

	pop = (*stack)->next;
	pop->prev = NULL;
	while (space->next != NULL)
		space = space->next;

	space->next = *stack;
	(*stack)->next = NULL;
	(*stack)->prev = space;
	(*stack) = pop;
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
