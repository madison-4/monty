#include "monty.h"
/**
 * addnode - add a node to the beginning
 * @head: address of the head
 * @n: integer data of the node
 * Return: address of the node
 */
stack_t *addnode(stack_t **head, int n)
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
	return (newnode);
}

/**
 *execute - function excutes the monty instruction
 *@str: line pointer
 *@head: head pointer to stack
 *@counter: line number
 *@file: file pointer
 *
 *Return: alway 0 on success
 */

int execute(char *str, stack_t **head, unsigned int counter, FILE *file)
{
	char *opt;
	unsigned int i = 0;
	instruction_t operation[] = {
		{"push", func_push},
		{"pall", func_pall},
		{"pint", func_pint},
		{"pop", func_pop},
		{"swap", func_swap},
		{"add", func_add},
		{"nop", func_nop},
		{"sub", func_sub},
		{"mul", func_mul},
		{NULL, NULL}
	};

	opt = strtok(str, " \n\t");
	if (opt == NULL || opt[0] == '#')
		return (0);
	if (opt)
		monty.arg = strtok(NULL, " \n\t");
	while (operation[i].opcode && opt)
	{
		if (strcmp(opt, operation[i].opcode) == 0)
		{
			operation[i].f(head, counter);
			return (0);
		}
		i++;
	}
	if (opt && operation[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", counter, opt);
		if (file)
			fclose(file);
		freelist(*head);
		exit(EXIT_FAILURE);
	}
	return (1);
}

/**
 * freelist - function that frees a stack
 * @head: head pointer of the stack
 */

void freelist(stack_t *head)
{
	stack_t *temp = head;

	while (head)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}
/**
 * printint -  prints the value at the top of the stack
 * @head: double head pointer of the stack
 * @line_counter: line number
 */
void printint(stack_t **head, unsigned int line_counter)
{
	stack_t *temp = *head;

	if (temp == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_counter);
		if (monty.file)
			fclose(monty.file);
		if (monty.str)
			free(monty.str);
		freelist(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", temp->n);
}
