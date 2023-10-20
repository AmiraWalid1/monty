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
		{"push", S_push},
		{"pall", S_pall},
		{"pint", S_pint},
		{"pop", S_pop},
		{"swap", swap_the_top},
		{"add", S_add},
		{"nop", S_nop},
		{"sub", S_sub},
		{"div", S_div},
		{"mul", S_mul},
		{"mod", S_mod},
		{"pchar", S_pchar},
		{"pstr", S_pstr},
		{"rotl", S_rotl}
	};
	sz_list_fun = sizeof(list_fun) / sizeof(list_fun[0]);
	if (global_variable.arr[0][0] == '#')
	{
		S_nop(S_top, line_number);
		return;
	}
	for (idx = 0 ; idx < sz_list_fun ; idx++)
	{
		if (strcmp(global_variable.arr[0], list_fun[idx].opcode) == 0)
		{
			list_fun[idx].f(S_top, line_number);
			return;
		}
	}
	fprintf(stderr, "L%u: unknown instruction %s\n"
	, line_number, global_variable.arr[0]);
	_free_global_variable();
	free(global_variable.arr);
	exit(EXIT_FAILURE);
}
