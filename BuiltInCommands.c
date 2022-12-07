#include "simple_shell.h"

/**
 * get_builtin - runs through and tries to find built-in commands
 * @self: double pointer back to shell interpreter
 * @command: the command we're looking for as a string
 * 
 * Return: funciton pointer to back to command to execute
*/
void (*get_builtin(char *command))(SimpleShell_t **)
{
    int i;
    BuiltInCommand_t builtins[] = {
        {"clear", clear_screen},
        {"cls", clear_screen},
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
 * clear_screen - exactly what it says on the tin
 * @self: double pointer back to shell interpreter
 */
void clear_screen(SimpleShell_t **self)
{
    (void)self;
    printf("WE WOULD CLEAR THE SCREEN IF WE COULD...\n");
}

/**
 * quit_repl - quit interactive mode
 * @self: double pointer back to shell interpreter
 * Description: PLACEHOLDER
 */
void quit_repl(SimpleShell_t **shell)
{
    ((*shell)->is_active) = FALSE;
}

/**
 * print_env_variables - print list of enviornmental variables.
 * @self: double pointer back to shell interpreter
 * Description: PLACEHOLDER
 */
void print_env_variables(SimpleShell_t **shell)
{
    (void)shell;
}
