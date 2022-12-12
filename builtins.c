#include "simple_shell.h"

/**
 * quit_repl - quit interactive mode
 * @shell: double pointer back to shell interpreter
 * Description: PLACEHOLDER
 */
void quit_repl(SimpleShell_t **shell)
{
	((*shell)->is_active) = FALSE;
}

/**
 * print_env_variables - print list of enviornmental variables.
 * @shell: double pointer back to shell interpreter
 * Description: PLACEHOLDER
 */
void print_env_variables(SimpleShell_t **shell)
{
	int i = 0;

	do {
		printf("%s\n", (*shell)->enviornment[i++]);
	} while ((*shell)->enviornment[i]);
}

/**
 * throw_error - dispaly an error message by designated number
 * @shell: double-pointer back to the interpreter (includes error num)
 */
void throw_error(SimpleShell_t **shell, int error_num)
{
	char specific_error[20];
	char error_message[255];

	if (error_num == 1)
		snprintf(specific_error, 20, "%s", "Permission denied\n");
	else if (error_num == 2)
		snprintf(specific_error, 20, "%s", "not found\n");
	else if (error_num == 3)
		snprintf(specific_error, 20, "%s", "Can't open\n");
	else
		snprintf(specific_error, 20, "%s", "Unknown Error\n");

	snprintf(
		error_message,
		255,
		"%s: %d: %s: %s",
		getenv("_"),
		(*shell)->line_num,
		(*shell)->command_args[0],
		specific_error
	);

	fprintf(stderr, "%s", error_message);
}
/**
 * is_only_spaces - Checks if a string contains only spaces
 * @string: The string to check
 * Return: 1 if the string is only spaces, 0 otherwise
 */

int is_only_spaces(char *string)
{
	int i = 0;

	while (string[i] != '\0')
	{
		if (string[i] != 32)
			return (FALSE);
		i++;
	}
	return (TRUE);
}
