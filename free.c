#include "monty.h"
/**
 * free_arr - free arr
 * @arr: arr will be freed
 *
 * Return: void.
*/
void free_arr(char **arr)
{
	int i;

	if (arr == NULL)
		return;
	for (i = 0 ; arr[i] ; i++)
	{
		free(arr[i]);
	}
	free(arr);
}
