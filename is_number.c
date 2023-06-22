#include "monty.h"

/**
 * is_number - checks if a string can be coneverted to interger.
 * @str: the string to check.
 *
 * Return: 1 if string can be converted, 0 otherwise.
 */
int is_number(char *str)
{
	int i;

	if (str == NULL || str[0] == '\0')
		return (0);

	for (i = 0; str[i] != '\0'; i++)
	{
		if (i == 0 && (str[i] == '-' || str[i] == '+'))
			continue;
		if (str[i] < '0' || str[i] > '9')
			return (0);
	}
	return (1);
}

/**
 * push_stack - adds a new node to the top of stack.
 * @stack: a pointer to the head of stack.
 * @i: value to store in the new node.
 *
 * Return: no return.
 */
void push_stack(stack_t **stack, int n)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	
	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = new_node;

	*stack = new_node;
}
