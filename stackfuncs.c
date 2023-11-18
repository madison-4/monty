#include "monty.h"
/**
 * remove_s - remove a node from the end of the list
 * @head: address of the head of the list
 * Return: the removed node
 *
 */
stack_t *remove_s(stack_t **head)
{
	stack_t *iter = *head, *former;

	while (iter->next)
		iter = iter->next;
	former = iter->prev;
	former->next = NULL;
	return (iter);
}
/**
 * add - add a node to the end of the list
 * @head: head of the list's address
 * @n: integer to be added
 * Return: address of the added node or NULL on failure
 */
stack_t *add(stack_t **head, int n)
{
	stack_t *temp, *newnode;
	if (head == NULL)
		return (NULL);
	newnode = malloc(sizeof(stack_t));
	if (!(newnode))
	{
		dprintf(2,"Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	newnode->n = n;
	if(*head == NULL)
	{
		newnode->next = *head;
		newnode->prev = NULL;
		*head = newnode;
		return(*head);
	}
	temp = *head;
	while (temp->next)
	{
		temp = temp->next;
	}
	newnode->next = temp->next;
	newnode->prev = temp;
	temp->next = newnode;
	return (temp->next);
}
/**
 * printall - print all elements of a linked list
 * @head: head of the list 
 * Return: number of to be printed
 */
void printall(stack_t **head, unsigned int line_no)
{
	stack_t *current;
	(void) line_no;
	current = *head;
	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

/**
 * push - a function to push element on top of a stuck
 * @stack: pointer to the top of stack
 * @line_no: line number in the file;
 * @arg: 
 *
 */
void push(stack_t **stack, unsigned int line_no, const char *arg)
{
	int value;
	stack_t *newnode;
	if (arg == NULL) /*||!isdigit(arg))*/
	{
		fprintf(stderr,"L%u: usage: push integer\n", line_no);
		exit(EXIT_FAILURE);
	}
	value = atoi(arg);
	newnode = malloc(sizeof(stack_t));
	if (newnode == NULL)
	{
		dprintf(2,"Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	newnode->n = value;
	newnode->prev = NULL;
	newnode->next = *stack;
	if(*stack != NULL)
	{
		(*stack)->prev = newnode;
	}
	*stack = newnode;
}
