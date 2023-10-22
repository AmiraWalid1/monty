#include "monty.h"
/**
 * split_line - split line to arr and return it
 * @line: ponter to line will be split
 *
 * Return: arr
*/
char **split_line(char *line)
{
	char *copy_line, *word_token;
	const char *delim = "\n ";
	int sz_arr = 0, idx;

	copy_line = _strdup(line);
	word_token = strtok(copy_line, delim);
	while (word_token)
	{
		sz_arr++;
		if (sz_arr == 2)
			break;
		word_token = strtok(NULL, delim);
	}
	sz_arr++;
	free(copy_line);
	copy_line = _strdup(line);
	global_variable.arr = malloc(sizeof(char *) * sz_arr);
	if (!global_variable.arr)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(copy_line);
		_free_global_variable();
		exit(EXIT_FAILURE);
	}
	word_token = strtok(copy_line, delim);
	for (idx = 0; idx < 2 && word_token ; idx++)
	{
		global_variable.arr[idx] = malloc(sizeof(char) * (strlen(word_token) + 1));
		if (!global_variable.arr[idx])
		{
			fprintf(stderr, "Error: malloc failed\n");
			free(copy_line);
			free_arr(global_variable.arr);
			_free_global_variable();
			exit(EXIT_FAILURE);
		}
		strcpy(global_variable.arr[idx], word_token);
		word_token = strtok(NULL, delim);
	}
	global_variable.arr[idx] = NULL;
	free(copy_line);
	return (global_variable.arr);
}
