#include "monty.h"
/**
 * main -The main function
 * @argc: Argument count
 * @argv[]: argument vector
 */
int main(int argc, char argv[])
{
	FILE *file_stream;
	char line;
	ssize_t r_data = 0;

	/*Checking if there is any file passed */
	if (!argv[])
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

	/*aloacting memeory for the line */
	line = malloc(sizeof(char) * 1024);

	/*checkinf if the line has nothing */
	if (line == NULL)
	{
		fprintf(stderr,"Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	/* reading data in the file */
	r_data = read(file_stream, line, 1024);

	if (r_data == -1)
	{
		free(line);
		exit(EXIT_FAILURE);
	}

	/* so here is where opcodes will be coming, I just tacked the error handling hehehe */
}
