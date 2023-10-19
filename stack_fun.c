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
		exit(EXIT_FAILURE);
	if (!arr[1] || _is_integer(arr[1]) == 0)
	{
		fprintf(stderr, "L<%d>: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = atoi(arr[1]);
	new_node->prev = NULL;
	new_node->next = *stack;
	if (*stack)
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
void S_pall(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	stack_t *curr;

	if (!stack)
		exit(EXIT_FAILURE);
	curr = *stack;
	while (curr)
	{
		fprintf(stdout,"%d\n", curr->n);
		curr = curr->next;
	}
}
