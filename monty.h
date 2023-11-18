#ifndef MONTY_H
#define MONTY_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <ctype.h>

#define _GNU_SOURCE

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

extern stack_t *top;

stack_t *remove_s(stack_t **head);
void printall(stack_t **head, unsigned int line_no);
stack_t *add(stack_t **head, int n);
void (*get_opcodes(char* opcode))(stack_t **stack, unsigned int line_no);
void push(stack_t **stack, unsigned int line_no, const char *arg);

/**
 *struct monty_t - defines global variables
 *@arg: argument passed
 *@str: line pointer
 *@file: file pointer
 *@set_stack: set structures to stack or queue
 */

typedef struct monty_t
{
	char *arg;
	char *str;
	FILE *file;
	int set_stack;
} monty_s;

extern monty_s monty;

int execute(char *str, stack_t **head, unsigned int counter, FILE *file);
void func_push(stack_t **head, unsigned  int line_number);
void func_pint(stack_t **head, unsigned int line_number);
void freelist(stack_t *head, unsigned int line_number);
void func_pop(stack_t **head, unsigned int line_number);
void func_swap(stack_t **head, unsigned int line_counter);
void func_add(stack_t **head, unsigned int line_counter);
void func_nop(stack_t **head, unsigned int line_number);
void func_sub(stack_t **head, unsigned int line_counter);
void func_mul(stack_t **head, unsigned int line_counter);

#endif
