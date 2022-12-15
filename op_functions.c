#include "monty.h"

int isNumber(char *str);
/**
* _push - push data into stack
* @head: pointer to top of stack
* @line_number: current line from source file
*
* Return: Nothing
*/

void _push(stack_t **head, unsigned int line_number)
{
	stack_t *new_item;
	int data = 0;

	if (monty_ip[1] == NULL || (isNumber(monty_ip[1]) == 0))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	data = atoi(monty_ip[1]);

	new_item = malloc(sizeof(stack_t));
	if (!new_item)
		malloc_failed();

	new_item->n = data;
	new_item->next = (*head);
	new_item->prev = NULL;

	if ((*head) != NULL)
		(*head)->prev = new_item;

	(*head) = new_item;
}

/**
* _print_stack - print all data availiable in stack
*
* @stack: pointer to top of the stack
* @line_number: line number of source file
*
* Return: Nothing
*/

void _print_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	(void) line_number;

	if (stack == NULL)
		return;

	current = *stack;

	while (current != NULL)
	{
		fprintf(stdout, "%d\n", current->n);
		current = current->next;
	}
}

/**
* isNumber - checks for number in string
* @stringArray: string to check
*
* Return: 1 if is number or 0 if is not number
*/

int isNumber(char *stringArray)
{
	int i;

	for (i = 0; stringArray[i] != '\000'; i++)
	{
		if (isdigit(stringArray[i]) == 0)
			return (0);
	}

	return (1);
}
