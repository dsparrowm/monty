#include "monty.h"

/**
* free_stack - frees a DLL stack
* @top: pointer to the top most element
* Return: Nothing
*/

void free_stack(stack_t *top)
{
	stack_t *current;

	while (top != NULL)
	{
		current = top;
		top = top->next;
		free(current);
	}
}

/**
* arr_len - calculate the length of monty_ip
*	(length of line instuction)
* Return: length of line
*/

int arr_len(void)
{
	int i;

	while ((monty_ip + i) != NULL)
	{
		printf("inst: %s \n", *(monty_ip + i));
		i++;
	}
	printf("len %d\n", i);
	return (i);
}
