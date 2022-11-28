#include "oop_monty.h"

/**
 * throw_error - prints relevant error message
 * @message: the specific error message
 * @line: line number (if any) -- 0 otherwise
 * @string: additional string (if any) -- "" otherwise
 *
 * Return: always returns EXIT_FAILURE
*/
int throw_error(char *message, int line, char *string)
{
	if (!line && !string)
		fprintf(stderr, message, "");
	else if (line && !string)
		fprintf(stderr, message, line);
	else if (!line && string)
		fprintf(stderr, message, string);
	else
		fprintf(stderr, message, line, string);

	return (EXIT_FAILURE);
}
