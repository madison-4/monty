#include "monty.h"

monty_s monty = {NULL, NULL, NULL, 0};

/**
 *main - main function
 *@argc: argument count
 *@argv: argument vector
 *Return: 0 on success
 */

int main(int argc, char *argv[])
{
	char *str;
	unsigned int count = 0;
	FILE *file;
	stack_t *stack = NULL;
	ssize_t line = 1;
	size_t size = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (line > 0)
	{
		str = NULL;
		line = getline(&str, &size, file);
		count++;
		if (line > 0)
		{
			execute(str, &stack, count, file);
		}
		free(str);
	}
	freenode(stack);
	fclose(file);

	return (0);
}
