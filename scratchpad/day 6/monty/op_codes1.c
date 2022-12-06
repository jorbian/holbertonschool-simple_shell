#include "monty.h"

/**
 * pall - Prints the values of a stack_t linked list.
 * @stack_pointer: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 *
 * Return: If the op returned an error.
 */
int pall(SSTAck_t **stack_pointer, unsigned int line_number)
{
	SSTAck_t *tmp = (*stack_pointer)->next;

	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
	(void)line_number;

	return (EXIT_SUCCESS);
}
/**
 * pint - Prints the top value of a stack_t linked list.
 * @stack_pointer: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 *
 * Return: If the op returned an error.
 */
int pint(SSTAck_t **stack_pointer, unsigned int line_number)
{
	if ((*stack_pointer)->next == NULL)
		return (throw_error(CANT_PINT, line_number, ""));

	printf("%d\n", (*stack_pointer)->next->n);

	return (EXIT_SUCCESS);
}
/**
 * nop - Does absolutely nothing for the Monty opcode 'nop'.
 * @stack_pointer: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 *
 * Return: If the op returned an error.
 */
int nop(SSTAck_t **stack_pointer, unsigned int line_number)
{
	(void)stack_pointer;
	(void)line_number;

	return (EXIT_SUCCESS);
}

/**
 * absolute_pop - Removes the end of the stack no questions asked.
 * @stack_pointer: A pointer to the top mode node of a stack_t linked list.
 */
void absolute_pop(SSTAck_t **stack_pointer)
{
	SSTAck_t *next = NULL;

	next = (*stack_pointer)->next->next;
	free((*stack_pointer)->next);
	if (next)
		next->prev = *stack_pointer;
	(*stack_pointer)->next = next;
}

/**
 * absolute_push - Adds a number to the stack no questions asked.
 * @stack_pointer: A pointer to the top mode node of a stack_t linked list.
 * @number: the number to be added.
 *
 * Return: If there was a malloc error or not.
 */
int absolute_push(SSTAck_t **stack_pointer, int number)
{
	SSTAck_t *new, *tmp;

	new = malloc(sizeof(SSTAck_t));
	if (new == NULL)
		return (throw_error(COULDNT_MALLOC, 0, ""));

	new->n = number;

	tmp = (*stack_pointer)->next;
	new->prev = *stack_pointer;
	new->next = tmp;
	if (tmp)
		tmp->prev = new;
	(*stack_pointer)->next = new;

	return (EXIT_SUCCESS);
}
