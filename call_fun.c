#include "monty.h"
/**
 * call_fun - function that check what function is needed to call and call it.
 * @S_top: pointer to pointer to top of stack.
 * @line_number: number of line is excecuted.
 * Return: void.
*/
void call_fun(stack_t **S_top, unsigned int line_number)
{
	int sz_list_fun, idx;
	instruction_t list_fun[] = {
		{"push", &S_push},
		{"pall", &S_pall}
	};
	sz_list_fun = sizeof(list_fun) / sizeof(list_fun[0]);
	for (idx = 0 ; idx < sz_list_fun ; idx++)
	{
		if (strcmp(arr[0], list_fun[idx].opcode) == 0)
		{
			list_fun[idx].f(S_top, line_number);
			return;
		}
	}
}
