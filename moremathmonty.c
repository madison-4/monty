#include "monty.h"

/**
 * _swap - function that swap top elements of the stack
 * @head: head pointer of the stack
 * @line_counter: line number
 */

void _swap(stack_t **head, unsigned int line_counter)
{
	int val_swap;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_counter);
		if (monty.file)
			fclose(monty.file);
		if (monty.str)
			free(monty.str);
		freelist(head);
		exit(EXIT_FAILURE);
	}
	val_swap = (*head)->n;
	(*head)->n = (*head)->next->n;
	(*head)->next->n = val_swap;
}

/**
 * _add - function that adds two element at the stack
 * @head: head pointer to the stack
 * @line_counter: line number
 */

void func_add(stack_t **head, unsigned int line_counter)
{
	stack_t *temp;
	int element;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_counter);
		if (monty.file)
			fclose(monty.file);
		if (monty.str)
			free(monty.str);
		freelist(head);
		exit(EXIT_FAILURE);
	}
	element = (*head)->n + (*head)->next->n;
	temp = *head;
	*head = (*head)->next;
	free(temp);
	(*head)->n = element;
}

/**
 * _nop - funtion that does nothing
 * @head: pointer of the head of the stack
 * @line_counter: line number
 */

void _nop(stack_t **head, unsigned int line_counter)
{
	(void)head;
	(void)line_counter;
}
