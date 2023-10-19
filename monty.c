#include "monty.h"
global_variable_t global_variable; 
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

	global_variable.S_top = NULL;
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
	global_variable.fd = file_d;
	/*read line by line from file*/
	for (line_number = 1; getline(&buff, &length, file_d) != -1 ; line_number++)
	{
		global_variable.buff = buff;
		if (_is_empty(buff))
			continue;
		global_variable.arr = split_line(buff);
		call_fun(&global_variable.S_top, line_number);
		free_arr(global_variable.arr);
	}
	free(buff);
	free_stack(&global_variable.S_top);
	/*close file*/
	fclose(file_d);
	return (0);
}