#include "monty.h"

/**
 * _sub - function that substract nodes
 * @head: head pointer to the stack
 * @line_counter: line number
 */

void _sub(stack_t **head, unsigned int line_counter)
{
	stack_t *temp;
	int result;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d:  can't sub, stack too short\n", line_counter);
		if (monty.file)
			fclose(monty.file);
		if (monty.str)
			free(monty.str);
		freelist(head);
		exit(EXIT_FAILURE);
	}
	result = (*head)->next->n - (*head)->n;
	temp = *head;
	*head = (*head)->next;
	free(temp);
	temp = *head;
	*head = (*head)->next;
	free(temp);
	add_node(head, result);

}

/**
 *func_mul - function that multiply nodes
 *@head: head pointer of the stack
 *@line_counter: line number
 */

void func_mul(stack_t **head, unsigned int line_counter)
{
	stack_t *temp;
	int res, len = 0;

	temp = *head;
	for (temp = *head; temp != NULL ; len++)
		temp = temp->next;
	if (len < 2)
	{
		fprintf(stderr, "L%d:  can't mul, stack too short\n", line_counter);
		if (monty.file)
			fclose(monty.file);
		if (monty.str)
			free(monty.str);
		freelist(head);
		exit(EXIT_FAILURE);
	}
	temp = *head;
	res = temp->next->n * temp->n;
	temp->next->n = res;
	*head = temp->next;
	free(temp);
}
