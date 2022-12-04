#include "monty.h"

/**
 * main - set up and then clean up fro interpret_script
 * @argc: number of arguments passed to program
 * @agrv: what those arguments were exactly as strings
 * 
 * Return: EXIT_SUCESS or EXIT_FAILURE (depending on what happens) 
 */
int main(int argc, char *argv[])
{
	int exit_status = 0;

	FILE *script_source = NULL;
	ScriptReader_t *script = NULL;
	MontyInterpreter_t *monty = NULL;

	if (argc != 2)
		return (throw_error(BAD_INPUT, 0, ""));

	exit_status = initialisation(&monty, &script);
	if (exit_status)
		return (exit_status);

	script_source = fopen(argv[1], "r");
	if (script_source == NULL)
	{
		free_script_reader(&script);
		free_monty(&monty);
		return (throw_error(BAD_FILE, 0, argv[1]));
	}
	load_script(&script, script_source);
	fclose(script_source);

	exit_status = interpret_script(&monty, &script);

	free_script_reader(&script);
	free_monty(&monty);

	return (exit_status);
}
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
/**
 * initialisation - create the ScriptReader and Interpreter
 * @monty: double pointer back to monty
 * @script: doubple pointer back to SR
 *
 * Return: If there was a problem allocating memory.
 */
int initialisation(MontyInterpreter_t **monty, ScriptReader_t **script)
{
	int malloc_failure_status = FALSE;

	malloc_failure_status = create_script_reader(script);
	if (malloc_failure_status)
		return (malloc_failure_status);

	malloc_failure_status = create_monty(monty);
	if (malloc_failure_status)
	{
		free_script_reader(script);
		return (malloc_failure_status);
	}
	return (malloc_failure_status);
}
