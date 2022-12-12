#include "simple_shell.h"

/**
 * create_shell - allocate memory for the simple shell and set inotal values
 * @shell: double pointer back to the simple shell
 * @envp: enviornmental variables passed directly from main
 *
 * Return: Whether or not the shell was sucessfully created.
 */
void create_shell(SimpleShell_t **shell, char **envp)
{
	*shell = malloc(sizeof(SimpleShell_t));
	if (shell == NULL)
		return;

	((*shell)->line_num) = 0;
	((*shell)->exit_status) = 0;
	((*shell)->is_active) = TRUE;
	(*shell)->enviornment = envp;
	(*shell)->path_variable = split_string(getenv("PATH"), ":");
	(*shell)->command_args = NULL;
	(*shell)->os_command_path = NULL;
	(*shell)->builtin = NULL;
}

/**
 * parse_line - parses an individual line taken from a script or the REPL
 * @shell: double pointer back to the simple shell
 * @new_line: the new line to be parsed
 *
 * Description: WILL REQUIRE SIGNIFICANT OVERHALL TO SUPPORT PIPES!!!
*/
void parse_line(SimpleShell_t **shell, char *new_line)
{
	(*shell)->command_args = split_string(new_line, " ");

	(*shell)->builtin = get_builtin((*shell)->command_args[0]);

	(*shell)->os_command_path = find_command_path(shell);

	if ((*shell)->builtin != NULL)
		(*shell)->builtin(shell);
	else if ((*shell)->os_command_path != NULL)
		create_new_process(shell);
	else
		throw_error(shell, 2);
}
/**
 * free_shell - deallocates memory for the interpreter and its properties
 * @shell: double pointer back to the simple shell
 */
void free_shell(SimpleShell_t **shell)
{
	free_array((*shell)->path_variable);

	if ((*shell)->command_args)
		free_array((*shell)->command_args);

	free(*shell);
}
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
 * create_new_process - Forks a child process that is possessed by our argv
 * @shell: double-pointer back to the interpreter
 *
 * Return: void
 */
void create_new_process(SimpleShell_t **shell)
{
	pid_t id;
	int status;

	id = fork();
	if (id == -1)
		perror("Fork failed");
	else if (id > 0)
		wait(&status);
	else if (id == 0)
		execve(
			(*shell)->os_command_path,
			(*shell)->command_args,
			(*shell)->enviornment
		);
	if ((WIFEXITED(status)))
		((*shell)->exit_status) = WEXITSTATUS(status);
	if (id != 0)
	{
		fflush(stdout);
		fflush(stdin);
	}
	free((*shell)->os_command_path);
}
