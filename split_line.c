#include "monty.h"
/**
 * split_line - split line to arr and return it
 * @line: ponter to line will be split
 *
 * Return: arr
*/
char **split_line(char *line)
{
	char *copy_line, *word_token, **arr;
	const char *delim = " \n";
	int sz_arr = 0, idx;

	copy_line = _strdup(line, NULL);
	word_token = strtok(copy_line, delim);
	while (word_token)
	{
		sz_arr++;
		word_token = strtok(NULL, delim);
	}
	sz_arr++;
	free(copy_line);
	arr = malloc(sizeof(char *) * sz_arr);
	if (!arr)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	copy_line = _strdup(line, arr);
	word_token = strtok(copy_line, delim);
	for (idx = 0; word_token ; idx++)
	{
		arr[idx] = _strdup(word_token, arr);
		printf("%s ", arr[idx]);
		word_token = strtok(NULL, delim);
	}
	arr[idx] = NULL;
	printf("\n");
	return (arr);
}
