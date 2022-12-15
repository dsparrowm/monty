#include "monty.h"

char **monty_ip = NULL; /* Definition checked against declaration */

/**
* main - entry point
* @ac: argument count
* @av: argument vector
*
* Return: Aways (0)
*/

int main(int ac, char *av[])
{
	stack_t *stack = NULL;
	char *line = NULL;
	size_t line_number = 0, len = 0;
	FILE *stream;
	ssize_t nr;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	stream = fopen(av[1], "r");
	if (stream == NULL)
	{

		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}

	while ((nr = getline(&line, &len, stream)) != -1)
	{
		parse_line(line);
		line_number++;
		if (monty_ip[0] != NULL)
		{
			get_op_func(&stack, line_number);
			free(monty_ip);
		}
	}

	free(line);
	fclose(stream);
	free_stack(stack);
	return (0);
}
