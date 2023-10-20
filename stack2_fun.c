#include "monty.h"

/**
 * swap_the_top - function that swaps the top two elements of the stack
 * @stack: pointer to top node of the stack
 * @line_number: line number
 * Return: void
 */
void swap_the_top(stack_t **stack, unsigned int line_number)
{
	stack_t *curr;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		_free_global_variable();
		free(global_variable.arr);
		exit(EXIT_FAILURE);
	}
	curr = (*stack)->next;
	(*stack)->next = curr->next;
	if (curr->next != NULL)
		curr->next->prev = *stack;
	curr->next = *stack;
	(*stack)->prev = curr;
	curr->prev = NULL;
	*stack = curr;
}
/**
 * S_pchar - prints the char at the top of the stack, followed by a new line.
 * @stack: pointer to top node of the stack
 * @line_number: line number
 * Return: void
*/
void S_pchar(stack_t **stack, unsigned int line_number)
{
	int n_top;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		_free_global_variable();
		free_arr(global_variable.arr);
		exit(EXIT_FAILURE);
	}
	n_top = (*stack)->n;
	if ((n_top >= 'a' && n_top <= 'z') || (n_top >= 'A' && n_top <= 'Z'))
	{
		printf("%c\n", n_top);
	}
	else
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		_free_global_variable();
		free_arr(global_variable.arr);
		exit(EXIT_FAILURE);
	}
}
