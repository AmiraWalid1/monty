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
/**
 * _is_integer - check if str is interger or not.
 * @str: string
 * Return: (0)false | (1)True.
*/
int _is_integer(char *str)
{
	size_t idx;

	for (idx = 0 ; idx < strlen(str) ; idx++)
	{
		if (str[idx] < '0' || str[idx] > '9')
		{
			if (idx == 0 && str[0] == '-')
				continue;
			return (0);
		}
	}
	return (1);
}
/**
 * _is_empty - check if str is empty or not.
 * @str: string
 * Return: (0)false | (1)True.
*/
int _is_empty(char *str)
{
	size_t idx;

	for (idx = 0 ; idx < strlen(str) - 1 ; idx++)
	{
		if (str[idx] != ' ')
			return (0);
	}
	return (1);
}
