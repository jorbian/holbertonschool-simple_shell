#include "simple_shell.h"

/**
 * num_of_spaces - Number of elements in the array split_string will return.
 * @string: The string to evaluate
 * @delimiter: Where we want to break that string up.
 * Return: The number of spaces to store the data, trailing NULL excluded
 */
int num_of_spaces(char *string, char *delimiter)
{
	int i = 0;
	int count = 1;
	int has_space = TRUE;
	char delim = delimiter[0];

	if (string[i] == '\0' || string == NULL)
		return (0);

	while (string[i] != '\0')
	{
		if (string[i] == delim)
		{
			if (has_space == 0)
			{
				count++;
				has_space = TRUE;
			}
		}
		else
			has_space = FALSE;
		i++;
	}
	return (count);
}

/**
 * split_string - exactly what it says on the tin
 * @string_to_split: the string we are breaking up
 * @delimiter: where we are breaking the string up
 * Return: A double pointer which is a list of strings split up
 */
char **split_string(char *string_to_split, char *delimiter)
{
	char **ret_array;
	int i = 0;
	long int length = num_of_spaces(string_to_split, delimiter);
	char *token_buffer;
	char *copy_of_string;
	char *grabtok;

	copy_of_string = strdup(string_to_split);
	ret_array = malloc(sizeof(char *) * (length + 255));

	if (length > 1)
	{
		token_buffer = strdup(strtok(copy_of_string, delimiter));
		ret_array[i] = token_buffer;

		while (token_buffer != NULL)
		{
			i++;
			grabtok = strtok(NULL, delimiter);
			if (grabtok == NULL)
			{
				ret_array[i] = NULL;
				break;
			}
			token_buffer = strdup(grabtok);
			ret_array[i] = token_buffer;
		}
	}
	else
		ret_array[i] = strdup(copy_of_string);

	free(copy_of_string);

	return (ret_array);
}
/**
 * free_array - deallocates memory allocated through split_string function
 * @an_array: the array that needs to be deallocated.
*/
void free_array(char **an_array)
{
	int i;

	for (i = 0; an_array[i]; i++)
		free(an_array[i]);
	free(an_array);
}

/**
 * find_command_path - attempts to find executable path to argv[0]
 * @shell: double pointer back to interpreter.
 *
 * Return: pointer if found, NULL not found
 */
char *find_command_path(SimpleShell_t **shell)
{
	struct stat file_info;
	char *command_path;
	int i = 0;

	command_path = (*shell)->command_args[0];

	while ((*shell)->path_variable[i])
	{
		if (stat(command_path, &file_info) == 0)
			return (command_path);

		command_path = create_test_path(
			(*shell)->path_variable[i++],
			(*shell)->command_args[0]
		);
	}
	free(command_path);

	return (NULL);
}

/**
 * create_test_path - Concatenate command argv[0] to each directory path
 * @dir_path: pointer a one dir PATH
 * @command: command
 *
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

	test_path = malloc(sizeof(char) * total_path_len + 2);

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
