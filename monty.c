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
	unsigned int line_number;
	char *buff = NULL;
	size_t length = 0;
	stack_t *S_top = NULL;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	/*open file*/
	file_d = fopen(av[1], "r");
	if (file_d == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	/*read line by line from file*/
	for (line_number = 1; getline(&buff, &length, file_d) != -1 ; line_number++)
	{
		if (_is_empty(buff))
			continue;
		arr = split_line(buff);
		call_fun(&S_top, line_number);
		free_arr(arr);
	}
	free(buff);
	free_stack(&S_top);
	/*close file*/
	fclose(file_d);
	return (0);
}
