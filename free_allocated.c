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
/**
 * free_stack - free stack.
 * @stack: pointer to pointer to top of stack.
 * Return: void.
*/
void free_stack(stack_t **stack)
{
	stack_t *curr, *freed_node;

	if (!stack)
		return;
	curr = *stack;
	while (curr)
	{
		freed_node = curr;
		curr = curr->next;
		free(freed_node);
	}
}
/**
 * _free_global_variable - free buff and stack and close file.
 * Return: void
*/
void _free_global_variable(void)
{
	free(global_variable.buff);
	free_stack(&global_variable.S_top);
	fclose(global_variable.fd);
}
