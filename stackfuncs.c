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
	stack_t *iter = *head, *new;
	new = malloc(sizeof(stack_t));
	if (!(new))
	{
		printf("Error\n");
		exit(0);
	}
	new->next = NULL;
	new->n = n;
	while (iter->next)
		iter = iter->next;
	iter->next = new;
	new->prev = iter;
	return (new);
}
/**
 * printall - print all elements of a linked list
 * @head: head of the list
 * @line_no: The line number 
 * Return: number of nodes printed
 */
void printall(stack_t **head, unsigned int line_no)
{
	stack_t *current = *head;
	(void) line_no;
	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
