#include "monty.h"
/**
 * main -The main function
 * @argc: Argument count
 * @argv[]: argument vector
 */
int main(int argc, char *argv[])
{
	FILE *file_stream;
	char *line = NULL;
	size_t len = 0;
	ssize_t r_data = 0;
	unsigned int line_no = 0;
	char *opcode = strtok(line,"\n\t\r;:");
	char *arg = strtok(NULL, "\t\n\r;:");
	int i;
	int found = 0;

	/*Checking if there is any file passed */
	if (argc != 2)
	{
		fprintf(stderr,"USAGE:monty file\n");
		exit(EXIT_FAILURE);
	}

	/*Opening the file passed */
	file_stream = open(argv[1], 'r');

	/* if the file failed to open */
	if (file_stream == -1)
	{
		fprintf(stderr,"Cannot open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	/*aloacting memeory for the line
	line = malloc(sizeof(char) * 1024);

	*checkinf if the line has nothing
	if (line == NULL)
	{
		fprintf(stderr,"Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	* reading data in the file line by line */

	r_data = getline(&line, &len, file_stream);

	/*if (r_data == -1)
	{
		free(line);
		exit(EXIT_FAILURE);
	}*/

	while (r_data != -1)
	{
		line_no++;

		/*Tokenizing the line to get the opcode and its argument */
		if (opcode != NULL)
		{
			for (i = 0; i < NUM_OPCODES; i++)
			{
				if (strcmp(opcode, opcodes[i].opcode) == 0)
				{
					opcodes[i].f(stack, line_no);
					found = 1;
					break;
				}
			}
			if (!found)
			{
				fprintf(stderr, "L%d: unkwnown instruction %s\n", line_no, opcode);
				free(line);
				fclose(file_stream);
				exit(EXIT_FAILURE);
			}
		}
	}
	/* free line and close the file */
	free(line);
	fclose(file_stream);

	return EXIT_SUCCESS;
}
