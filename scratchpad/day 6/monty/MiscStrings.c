#include "monty.h"

/**
 * only_spaces - Checks if a string contains only spaces
 * @str: The string to check
 * Return: 1 if the string is only spaces, 0 otherwise
 */
int only_spaces(char *string)
{
	int i = 0;

	while (string[i] != '\0')
	{
		if (string[i] != 32)
			return (0);
		i++;
	}
	return (1);
}
/**
 * space_count - Counts the number of buckets to allocate to store the data
 *               when given a string delimiter of the data
 * @str: The string to evaluate
 * @delimiter: The string that is breaking up str
 * Return: The number of spaces to store the data, trailing NULL excluded
 */
int space_count(char *str, char *delimiter)
{
	int i = 0;
	int count = 1;
	int got_space = 1;
	char delim = delimiter[0];

	if (str[i] == '\0' || str == NULL)
		return (0);

	while (str[i] != '\0')
	{
		if (str[i] == delim)
		{
			if (got_space == 0)
			{
				count++;
				got_space = 1;
			}
		}
		else
			got_space = 0;
		i++;
	}
	return (count);
}
