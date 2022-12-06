#include "oop_monty.h"

/**
 * create_stack- Initializes the SSTAck_t stack
 * @stack_pointer: exactly what it says on the tin.
 * Return: 0 for sucess, 1 for failure
 */
int create_stack(SSTAck_t **stack_pointer)
{
	SSTAck_t *s;

	s = malloc(sizeof(SSTAck_t));
	if (s == NULL)
		return (throw_error(COULDNT_MALLOC, 0, ""));

	s->n = 0;
	s->prev = NULL;
	s->next = NULL;

	*stack_pointer = s;

	return (EXIT_SUCCESS);
}

/**
 * free_stack - deallocates memory from stack
 * @stack_pointer: exactly what it says on the tin.
*/
void free_stack(SSTAck_t **stack_pointer)
{
	SSTAck_t *tmp1;

	while (*stack_pointer)
	{
		tmp1 = (*stack_pointer)->next;
		free(*stack_pointer);
		*stack_pointer = tmp1;
	}
}
