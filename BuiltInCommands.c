#include "simple_shell.h"

/**
 * get_builtin - runs through and tries to find built-in commands
 * @command: the command we're looking for as a string
 *
 * Return: funciton pointer to back to command to execute
*/
void (*get_builtin(char *command))(SimpleShell_t **)
{
	int i;
	BuiltInCommand_t builtins[] = {
		{"exit", quit_repl},
		{"quit", quit_repl},
		{"env", print_env_variables},
		{NULL, NULL}
	};

	for (i = 0; builtins[i].name; i++)
	{
		if (strcmp(command, builtins[i].name) == 0)
			return (builtins[i].exec);
	}
	return (NULL);
}
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
	(void)shell;
}
