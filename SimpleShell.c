#include "simple_shell.h"

/**
 * create_shell - allocate memory for the simple shell and set inotal values
 * @shell: double pointer back to the simple shell
 * @envp: enviornmental variables passed directly from main
 *
 * Return: Whether or not the shell was sucessfully created.
 */
int create_shell(SimpleShell_t **shell, char **envp)
{
	*shell = malloc(sizeof(SimpleShell_t));
	if (shell == NULL)
		return (EXIT_FAILURE);

	((*shell)->line_num) = 0;
	((*shell)->exit_status) = 0;
	((*shell)->is_active) = TRUE;
	((*shell)->error_num) = 0;
	(*shell)->enviornment = envp;
	(*shell)->path_variable = split_string(
		_getenv(envp, "PATH"),
		":"
	);
	(*shell)->os_command_path = NULL;
	(*shell)->builtin = NULL;

	return (EXIT_SUCCESS);
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
	((*shell)->error_num) = 0;

	(*shell)->command_args = split_string(new_line, " ");

	(*shell)->builtin = get_builtin((*shell)->command_args[0]);

	if ((*shell)->builtin != NULL)
	{
		(*shell)->builtin(shell);
		return;
	}

	(*shell)->os_command_path = find_command_path(shell);

	if ((*shell)->os_command_path != NULL)
		create_new_process(shell);

	free_array((*shell)->command_args);
}

/**
 * free_shell - deallocates memory for the interpreter and its properties
 * @shell: double pointer back to the simple shell
 */
void free_shell(SimpleShell_t **shell)
{
	free_array((*shell)->path_variable);
	free_array((*shell)->command_args);
	free(*shell);
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
}

/**
 * _getenv - Custom getenv function
 * @envp: the enviornmental variable array
 * @key: specific key (such as 'PATH') that we're looking for
 *
 * Return: The value of the environment variable
 */
char *_getenv(char **envp, char *key)
{
	int i = 0;
	int j = 0;
	char *retval;
	char copyenv[PATH_MAX];

	while (envp[i])
	{
		j = 0;
		strcpy(copyenv, envp[i]);
		while (copyenv[j] != '\0' && copyenv[j] != '=')
			j++;

		copyenv[j] = '\0';
		j++;
		if (strcmp(copyenv, key) == 0)
		{
			retval = &envp[i][j];
			return (retval);
		}
		i++;
	}
	return (NULL);
}
