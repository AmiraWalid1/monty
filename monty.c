#include "monty.h"
char **arr;
/**
 * main - Entry point
 * @ac: arguments counter
 * @av: argument vector
 * Return: Always 0 (success)
 */
int main(int ac, char *av[])
{
	FILE *file_d;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file_d = open_the_file(av[1]);
	read_line(file_d);
	fclose(file_d);
	return (0);
}

/**
 * open_the_file - function that opens the file and return pointer to FILE
 * @f_name: file name
 * Return: pointer to FILE struct
 */
FILE *open_the_file(char *f_name)
{
	FILE *file_d = fopen(f_name, "r");

	if (f_name == NULL || file_d == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", f_name);
		exit(EXIT_FAILURE);
	}
	return (file_d);
}

/**
 * read_line - function that read from file ,
 * call split_line fun and call call_fun fun.
 * @file_d: pointer to file descriptor
 * Return: void
 */
void read_line(FILE *file_d)
{
	unsigned int line_number;
	char *buff = NULL;
	size_t length = 0;
	stack_t *S_top = NULL;

	for (line_number = 1; getline(&buff, &length, file_d) != -1 ; line_number++)
	{
		arr = split_line(buff);
		call_fun(&S_top, line_number);
		free_arr(arr);
	}
	free(buff);
}
