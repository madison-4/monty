#include "monty.h"

/**
 *add_node - function that adds a node in stack
 *@head: head pointer of the stack
 *@n: node to be added
 */

void add_node(stack_t **head, int n)
{
	stack_t *newnode;

	newnode = malloc(sizeof(stack_t));
	if (newnode == NULL)
	{
		printf("Error\n");
		exit(0);
	}
	newnode->n = n;
	newnode->prev = NULL;
	newnode->next = *head;

	if (*head)
		(*head)->prev = newnode;
	*head = newnode;

}

/**
 * _push - function that add a node at the stack
 * @head: headpointer to the stack
 * @line_counter: count the line
 */

void _push(stack_t **head, unsigned int line_counter)
{
	int i, j = 0, flag = 0;

	if (monty.arg)
	{
		if (monty.arg[0] == '-')
			j++;
		while (monty.arg[j] != '\0')
		{
			if (monty.arg[j] < '0' || monty.arg[j] > '9')
				flag = 1;
			j++;
		}
		if (flag == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_counter);
			if (monty.file)
				fclose(monty.file);
			if (monty.str)
				free(monty.str);
			freelist(head);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_counter);
		if (monty.file)
			fclose(monty.file);
		if (monty.str)
			free(monty.str);
		freelist(head);
		exit(EXIT_FAILURE);
	}
	i = atoi(monty.arg);
	if (monty.set_stack == 0)
		add_node(head, i);
}
