#include "monty.h"

/**
 * freelist - function that frees a stack
 * @header: head pointer of the stack
 */

void freelist(stack_t **header)
{
	stack_t *temp = *header, *head = *header;

	while (head)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}
/**
 * _pall - function that prints the stack
 * @head: double pointer the stack
 * @count: unused line count
 *  This is included for the func poiter's sake
 */

void _pall(stack_t **head, unsigned int count)
{
	stack_t *temp;
	(void)count;

	if (*head == NULL)
		return;
	temp = *head;
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * _pint - prints the value at the top of the stack
 * @head: double head pointer of the stack
 * @line_counter: line number
 */

void _pint(stack_t **head, unsigned int line_counter)
{
	stack_t *temp = *head;

	if (temp == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_counter);
		if (monty.file)
			fclose(monty.file);
		if (monty.str)
			free(monty.str);
		freelist(head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", temp->n);
}

/**
 * _pop - function that removes the top element of the stack
 * @head: doubly pointer to the stack
 * @line_counter: line number
 */

void _pop(stack_t **head, unsigned int line_counter)
{
	stack_t *temp;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_counter);
		if (monty.file)
			fclose(monty.file);
		if (monty.str)
			free(monty.str);
		freelist(head);
		exit(EXIT_FAILURE);
	}
	temp = *head;
	*head = temp->next;
	free(temp);
}
