#include "monty.h"

/**
* parse_line - parse each line read from the source stream
*	to remove white spaces
*
* @line: string read from source
*
* Return: NOthing;
*/

void parse_line(char *line)
{
	int buffsz = BUFFSIZE, i = 0;
	char *token;

	monty_ip = malloc(buffsz * sizeof(char *));
	if (!monty_ip)
	{
		free(monty_ip);
		malloc_failed();
	}

	token = strtok(line, TOKEN_DELIMITER);
	while (token != NULL)
	{
		monty_ip[i] = strdup(token);
		i++;
		token = strtok(NULL, TOKEN_DELIMITER);
	}

	monty_ip[i] = NULL;
}

/**
* malloc_failed - malloc fails handler
*/
void malloc_failed(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	exit(EXIT_FAILURE);
}

