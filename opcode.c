#include "monty.h"

void (*get_opcodes(char* opcode))(stack_t **stack, unsigned int line_no)
{
	int i;

	instruction_t instructions[] = {
		{"printall", printall},
		{NULL, NULL}
	
	};

	while (instructions[i].f != NULL)
	{
		if (strcmp(opcode, instructions[i].opcode) == 0)
		{
			return (instructions[i].f);
		}
		i++;
	}
	return (NULL);
}
