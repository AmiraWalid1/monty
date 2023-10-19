#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct global_variable_s - global variables.
 * @buff: buffer that will use to read lines.
 * @arr: arr that will conatain line will be readed after split.
 * @S_top: top of stack.
 * @fd: file descripter of given file.
 *
 * Description: global variables.
*/
typedef struct global_variable_s
{
	char *buff;
	char **arr;
	stack_t *S_top;
	FILE *fd;
} global_variable_t;

extern global_variable_t global_variable;

/* monty.c */
int main(int ac, char *av[]);
FILE *open_the_file(char *f_name);
void read_line(FILE *file_d);
/*split_line.c*/
char **split_line(char *line);
/*free.c*/
void free_arr(char **arr);
void free_stack(stack_t **stack);
/*str_fun.c*/
char *_strdup(char *src);

void call_fun(stack_t **S_top, unsigned int line_number);
void S_push(stack_t **stack, unsigned int line_number);
void S_pall(stack_t **stack, unsigned int line_number);
void S_pint(stack_t **stack, unsigned int line_number);
int _is_integer(char *str);
int _is_empty(char *str);
void swap_the_top(stack_t **stack, unsigned int line_number);
void S_add(stack_t **stack, unsigned int line_number);
void S_nop(stack_t **stack, unsigned int line_number);
void S_pop(stack_t **stack, unsigned int line_number);
void _free_global_variable(void);
void S_sub(stack_t **stack, unsigned int line_number);
void S_div(stack_t **stack, unsigned int line_number);
void S_mul(stack_t **stack, unsigned int line_number);
void S_mod(stack_t **stack, unsigned int line_number);
#endif
