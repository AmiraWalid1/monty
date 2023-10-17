#include "monty.h"
/**
 * _strdup - function return a poiter to new string duplicated of string src.
 * @src: string will be duplicated.
 *
 * Return: pointer to new string.
*/
char *_strdup(char *src)
{
	char *dis;

	if (src == NULL)
		return (NULL);
	dis = malloc(sizeof(char) * (strlen(src) + 1));
	if (!src)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	strcpy(dis, src);
	return (dis);
}
