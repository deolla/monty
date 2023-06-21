#include "monty.h"

/**
 * main - start of function.
 * @argc: number of argument.
 * @argv: array of argument.
 *
 * Return: success.
 */
int main(int argc, char *argv[])
{
	const char *filename;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	filename = argv[1];
	process_file(filename);

	return (EXIT_SUCCESS);
}
