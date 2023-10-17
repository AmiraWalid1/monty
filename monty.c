#include "monty.h"

/**
 * main - Entry point
 * @ac: arguments counter
 * @av: argument vector
 * Return: Always 0 (success)
 */
int main(int ac, char *av[])
{
	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	read_line(av[1]);
	return (0);
}

/**
 * open_the_file - function that opens the file
 * @f_name: file name
 */
void open_the_file(char *f_name)
{
	FILE *file_d = fopen(file_name, "r");

        if (file_name == NULL || file_d == NULL)
        {
                fprintf(stderr, "Error: Can't open file %s\n", file_name);
                exit(EXIT_FAILURE);
	}
	read_line(file_d);
	fclose(file_d);
}

/**
 * read_line - function that opens the file and read from it
 * @file_d: pointer to file descriptor
 * Return: void
 */
void read_line(FILE *file_d)
{
	int line;
	char *buff = NULL;
	size_t length = 0;

	for (line == 1; getline(&buff, &length, file_d) != -1; line++)
	{
		/* parse line */
	}
	free(buff);
}
