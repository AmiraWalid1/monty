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
 * S_add - function that adds the top two elements of the stack
 * @stack: pointer to top node of the stack
 * @line_number: line number
 * Return: void
 */
void S_add(stack_t **stack, unsigned int line_number)
{
	stack_t *top;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
<<<<<<< HEAD
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
=======
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		_free_global_variable();
		free(global_variable.arr);
>>>>>>> a00ea6e7128ccb3c1f825b736f90ebc09a0824d8
		exit(EXIT_FAILURE);
	}
	top = *stack;
	*stack = (*stack)->next;
	(*stack)->n += top->n;
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
