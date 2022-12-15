#include"monty.h"

static instruction_t funcs[] = {
		{"push", _push},
		{"pall", _print_stack},
		{"NULL", NULL}
	};
/**
* get_op_function - gets the function associated with the povided opcode
*	key/value from an array
*
* @stack: used to store values
* @line_number: instrution
*
* Return: Nothing
*/

void get_op_func(stack_t **stack, unsigned int line_number)
{
	int i = 0;
	char *opcode = monty_ip[0];

	while (funcs[i].opcode != NULL)
	{
		if ((strcmp(opcode, funcs[i].opcode)) == 0)
		{
			funcs[i].f(stack, line_number);
			break;
		}

		if ((strcmp(opcode, funcs[i].opcode) != 0)
			&& funcs[i + 1].opcode == NULL)
		{
			fprintf(stderr, "L%u: unknown instruction %s\n",
				line_number,
				opcode);
			exit(EXIT_FAILURE);
		}

		i++;
	}
}
