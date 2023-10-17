#include "monty.h"
/**
 * _strdup - function return a poiter to new string duplicated of string src.
 * @src: string will be duplicated.
 * @arr: pointer to arr that allocated to free it if duplicated failed.
 *
 * Return: pointer to new string.
*/
char *_strdup(char *src, char **arr)
{
	char *dis;

	if (src == NULL)
		return (NULL);
	dis = malloc(sizeof(char) * (strlen(src) + 1));
	if (!src)
	{
		if (arr != NULL)
			free_arr(arr);
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	strcpy(dis, src);
	return (dis);
}
