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
	int add;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack) = (*stack)->next;
	add = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = add;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * S_sub - function that subtracts the top element of the stack
 * from the second top element of the stack
 * @stack: pointer to top node of the stack
 * @line_number: line number
 * Return: void
 */
void S_sub(stack_t **stack, unsigned int line_number)
{
	int sub;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
        {
                fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
                exit(EXIT_FAILURE);
        }
	(*stack) = (*stack)->next;
	sub = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = sub;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
