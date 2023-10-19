#include "monty.h"

/**
 * S_push - function that pushes an element to the stack.
 * @stack: pointer to pointer to top of stack.
 * @line_number: number of line is excecuted.
 * Return: void.
*/
void S_push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;

	if (!stack)
		return;
	if (!global_variable.arr[1] || _is_integer(global_variable.arr[1]) == 0)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		free_arr(global_variable.arr);
		_free_global_variable();
		exit(EXIT_FAILURE);
	}
	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_arr(global_variable.arr);
		_free_global_variable();
		exit(EXIT_FAILURE);
	}
	new_node->n = atoi(global_variable.arr[1]);
	new_node->prev = NULL;
	new_node->next = *stack;
	
	(*stack)->prev = new_node;
	*stack = new_node;
}
/**
 * S_pall - prints all the values on the stack,
 * starting from the top of the stack.
 * @stack: pointer to pointer to top of stack.
 * @line_number: number of line is excecuted.
 * Return: void.
*/
void S_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *curr;

	(void) line_number;
	if (stack == NULL)
		return;
	curr = *stack;
	while (curr != NULL)
	{
		printf("%d\n", curr->n);
		curr = curr->next;
	}
}
/**
 * S_pint - prints the value at the top of the stack, followed by a new line.
 * @stack: pointer to pointer to top of stack.
 * @line_number: number of line is excecuted.
 * Return: void.
*/
void S_pint(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		free_arr(global_variable.arr);
		_free_global_variable();
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
/**
 * S_pop - removes the top element of the stack.
 * @stack: pointer to pointer to top of stack.
 * @line_number: number of line is excecuted.
 * Return: void.
*/
void S_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *top;

	if (!stack || *stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		free_arr(global_variable.arr);
		_free_global_variable();
		exit(EXIT_FAILURE);
	}
	top = *stack;
	*stack = (*stack)->next;
	if (*stack)
		(*stack)->prev = NULL;
	free(top);
}

/**
 * S_nop - function doesn’t do anything
 * @stack: pointer to top node of the stack
 * @line_number: line number
 * Return: void
 */
void S_nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
