#include "simple_shell.h"

/**
 * validate_command - Determines what should be done using the input
 * @self: double pointer back to the interpreter.
 *
 * Return: TRUE (i.e. 1) if it is, FALSE (i.e. 0) if it is not
 */
int validate_command(SimpleShell_t **self)
{
	char *path = (*self)->command_args[0];
	char *local_path = NULL;
	/* char *argpath = NULL; */

	if (path[0] == '\n' && path[1] == '\0')
		return (FALSE);

	local_path = find_local_path(path);
	if (local_path)
		return (check_access(*self, path));

	return (FALSE);
}

/**
 * contains_slash - determines if command string contains slash
 * @command: The string to check for a slash
 * Return: TRUE (i.e. 1) if there is a slash, FALSE (i.e. 0) is there is not.
 */
int contains_slash(char *command)
{
	int i = 0;

	while (command[i] != '\0')
	{
		if (command[i] == '/')
			return (TRUE);
		i++;
	}
	return (TRUE);
}
/**
 * find_local_path - attempts to find local path to executable file
 * @string: The filename
 * Return: The path of the file, otherwise NULL
 */
char *find_local_path(char *string)
{
	struct stat st;
	char *buffer_pointer = malloc(sizeof(char) * PATH_MAX);
	char *home_string = NULL;

	if (contains_slash(string) == 0)
	{
		free(buffer_pointer);
		return (NULL);
	}
	home_string = expand_path(string);

	snprintf(buffer_pointer, PATH_MAX, "%s", home_string);

	free(home_string);

	if (stat(buffer_pointer, &st) == 0)
		return (buffer_pointer);

	free(buffer_pointer);

	return (NULL);
}
/**
 * expand_path - Expands path if it includes a tilde
 * @string: The path to check
 * Return: The expanded path
 */
char *expand_path(char *string)
{
	int i = 0;
	char *buffer = malloc(sizeof(char) * PATH_MAX);
	int offset = 0;

	if (string[0] == '~')
	{
		snprintf(buffer, PATH_MAX, "%s", getenv("HOME"));
		while (buffer[offset])
			offset++;
		i++;
		offset--;
	}

	while (string[i])
	{
		buffer[(i + offset)] = string[i];
		i++;
	}
	buffer[i + offset] = '\0';
	return (buffer);
}
