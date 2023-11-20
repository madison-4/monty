#include "monty.h"

/**
 * main - main function
 * @argc: argument count
 * @argv: argument vector
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
	monty_s monty = {NULL, NULL, NULL, 0};

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
			execute(str, &stack, count, file);
		free(str);
	}
	freelist(&stack);
	fclose(file);

	return (0);
}

/**
 *execute - function excutes the monty instruction
 *@str: line pointer
 *@head: head pointer to stack
 *@counter: line number
 *@file: file pointer
 *
 *Return: alway 0 on success
 */

int execute(char *str, stack_t **head, unsigned int counter, FILE *file)
{
	char *opt;
	unsigned int i = 0;
	instruction_t operation[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nop},
		{"sub", _sub},
		{"mul", _mul},
		{NULL, NULL}
	};

	opt = strtok(str, " \n\t");
	if (opt == NULL || opt[0] == '#')
		return (0);
	if (opt)
		monty.arg = strtok(NULL, " \n\t");
	while (operation[i].opcode && opt)
	{
		if (strcmp(opt, operation[i].opcode) == 0)
		{
			operation[i].f(head, counter);
			return (0);
		}
		i++;
	}
	if (opt && operation[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", counter, opt);
		if (file)
			fclose(file);
		freelist(head);
		exit(EXIT_FAILURE);
	}
	return (1);
}
