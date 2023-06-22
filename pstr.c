#include "monty.h"

/**
 * pstr - prints the string starting at the top of the stack.
 * @stack: a pointer to the head of stack.
 * @line_number: line number in file.
 *
 * Return: no return.
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *pop = *stack;
	(void)line_number;

	while (pop != NULL && pop->n > 0 && pop->n <= 127)
	{
		printf("%c", pop->n);
		pop = pop->next;
	}
	printf("\n");
}
