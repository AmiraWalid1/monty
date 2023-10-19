#include "monty.h"
/**
 * split_line - split line to arr and return it
 * @line: ponter to line will be split
 *
 * Return: arr
*/
char **split_line(char *line)
{
	char *copy_line, *word_token, **argv;
	const char *delim = "\n ";
	int sz_arr = 0, idx;

	copy_line = _strdup(line);
	word_token = strtok(copy_line, delim);
	while (word_token)
	{
		sz_arr++;
		word_token = strtok(NULL, delim);
	}
	sz_arr++;
	free(copy_line);
	copy_line = _strdup(line);
	argv = malloc(sizeof(char *) * sz_arr);
	if (!argv)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(copy_line);
		free(global_variable.buff);
		free_stack(&global_variable.S_top);
		fclose(global_variable.fd);
		exit(EXIT_FAILURE);
	}
	word_token = strtok(copy_line, delim);
	for (idx = 0; idx < 2 && word_token ; idx++)
	{
		argv[idx] = malloc(sizeof(char) * (strlen(word_token) + 1));
		if (!argv[idx])
		{
			fprintf(stderr, "Error: malloc failed\n");
			free(copy_line);
			free_arr(argv);
			free(global_variable.buff);
			free_stack(&global_variable.S_top);
			fclose(global_variable.fd);
			exit(EXIT_FAILURE);
		}
		strcpy(argv[idx], word_token);
		word_token = strtok(NULL, delim);
	}
	argv[idx] = NULL;
	free(copy_line);
	return (argv);
}
