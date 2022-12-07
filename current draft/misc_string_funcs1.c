#include "simple_shell.h"

/**
 * take_input - Receives input and makes it safe to process
 * Return: Parsed input from the user
 */
char *take_input(void)
{
	char *buffer;
	size_t n = 1;
	ssize_t check;
	char new_line[] = {'\n', '\0'};

		buffer = malloc(sizeof(char) * 1);

		check = (getline(&buffer, &n, stdin));
		if (check == -1)
		{
			free(buffer);
			exit(0);
		}
		if (buffer[0] == '\n' && buffer[1] == '\0')
			;
		else
		{
			buffer = strtok(buffer, new_line);
			if ((is_only_spaces(buffer)))
			{
				buffer[0] = '\n';
				buffer[1] = '\0';
			}
		}
		return (buffer);
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
	ret_array = malloc(sizeof(char *) * (length + 1));

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
	{
		ret_array[i] = strdup(copy_of_string);
	}
	ret_array[i + 1] = NULL;

	free(copy_of_string);

	return (ret_array);
}
/**
 * num_of_spaces - Counts the number of buckets to allocate to store the data
 *               when given a string delimiter of the data
 * @string: The string to evaluate
 * @delimiter: The string that is breaking up str
 * Return: The number of spaces to store the data, trailing NULL excluded
 */

int num_of_spaces(char *string, char *delimiter)
{
	int i = 0;
	int count = 1;
	int gotspace = TRUE;
	char delim = delimiter[0];

	if (string[i] == '\0' || string == NULL)
		return (0);

	while (string[i] != '\0')
	{
		if (string[i] == delim)
		{
			if (gotspace == 0)
			{
				count++;
				gotspace = TRUE;
			}
		}
		else
			gotspace = FALSE;
		i++;
	}
	return (count);
}
