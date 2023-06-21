#include "monty.h"

/**
 * push - insert element into the stack.
 * @stack: pointer to the head of the stack.
 * @line_number: line number in file.
 *
 * Return: no return.
 */
void push(stack_t **stack, unsigned int line_number)
{
	int p;
	char *values;
	stack_t *new_node;

	/* check if value is letters */
	values = strtok(NULL, " \n");
	if (values == NULL || !isdigit(*values))
	{
		fprintf(stderr, "L%u: usage: push interger\n", line_number);
		exit(EXIT_FAILURE);
	}

	/* Check if argument is valid interger using atoi */
	p = atoi(values);

	/* Create new node */
	new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = p;
	new_node->prev = NULL;

	if (*stack != NULL)
	{
		(*stack)->prev = new_node;
		new_node->next = *stack;
	}
	else
	{
		new_node->next = NULL;
	}
	*stack = new_node;
}

/**
 * pall - prints all values in the stack.
 * @stack: pointer to the head of stack.
 * @line_number: line number in file.
 *
 * Return: no return.
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current;
	(void)line_number;

	current = *stack;
	if (current == NULL)
		return;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
