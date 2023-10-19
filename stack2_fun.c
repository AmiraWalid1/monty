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
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
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
