#include "simple_shell.h"

/**
 * find_command_path - attempts to find executable path to argv[0]
 * @self: double pointer back to interpreter.
 * 
 * Return: pointer if found, NULL not found
 */
char *find_command_path(SimpleShell_t **self)
{
	struct stat file_info;
	char *command_path;
	int i = 0;

	if (stat((*self)->command_args[0], &file_info) == 0)
			return ((*self)->command_args[0]);

	while ((*self)->path_variable[i])
	{
		command_path = create_test_path(
            (*self)->path_variable[i],
            (*self)->command_args[0]
        );
		if (stat(command_path, &file_info) == 0)
			return (command_path);
		i++;
	}
	return (NULL);
}

/**
 * create_test_path - Concatenate command argv[0] to each directory path
 * @dpath: pointer a one dir PATH
 * @argv0: command
 * Return: pointer string dir + cmd or NULL error
 */
char *create_test_path(char *dir_path, char *command)
{
	int dir_path_len, command_len, total_path_len;
    int i = 0, j = 0;
	char *test_path;

	dir_path_len = strlen(dir_path);
	command_len = strlen(command);
	total_path_len = dir_path_len + command_len;

	test_path = calloc(total_path_len + 2, sizeof(char));
	if (test_path == NULL)
	{
		write(1, "Error: malloc catpath\n", 22);
		return (NULL);
	}
	while (dir_path[i])
	{
		test_path[i] = dir_path[i];
		i++;
	}
	test_path[i] = '/';
	i++;
	while (command[j])
		test_path[i++] = command[j++];
        
	test_path[i] = '\0';

	return (test_path);
}
