#include "monty.h"

/**
 * add - Adds the top two values of a stack_t linked list.
 * @stack_pointer: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 *
 * Description: Result is stored in second node and top is removed.
 * Return: If there was an error or not.
 */
int add(SSTAck_t **stack_pointer, unsigned int line_number)
{
	if ((*stack_pointer)->next == NULL || (*stack_pointer)->next->next == NULL)
		return (throw_error(SHORT_STACK, line_number, "add"));

	(*stack_pointer)->next->next->n += (*stack_pointer)->next->n;
	absolute_pop(stack_pointer);

	return (EXIT_SUCCESS);
}

/**
 * swap - Swaps the top two value elements of a stack_t linked list.
 * @stack_pointer: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 *
 * Return: If there was an error or not.
 */
int swap(SSTAck_t **stack_pointer, unsigned int line_number)
{
	SSTAck_t *tmp;

	if ((*stack_pointer)->next == NULL || (*stack_pointer)->next->next == NULL)
		return (throw_error(SHORT_STACK, line_number, "add"));

	tmp = (*stack_pointer)->next->next;
	(*stack_pointer)->next->next = tmp->next;
	(*stack_pointer)->next->prev = tmp;
	if (tmp->next)
		tmp->next->prev = (*stack_pointer)->next;
	tmp->next = (*stack_pointer)->next;
	tmp->prev = (*stack_pointer);
	(*stack_pointer)->next = tmp;

	return (EXIT_SUCCESS);
}

/**
 * pop - Removes the end of the stack no questions asked.
 * @stack_pointer: A pointer to the top mode node of a stack_t linked list.
 * @line_number: current blah blah blah
 */
int pop(SSTAck_t **stack_pointer, unsigned int line_number)
{
	if ((*stack_pointer)->next == NULL)
		return (throw_error(CANT_POP, line_number, ""));

	absolute_pop(stack_pointer);

	return (EXIT_SUCCESS);
}
/**
 * push - Does absolutely nothing for the Monty opcode 'nop'.
 * @stack_pointer: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 *
 * Return: If the op returned an error.
 */
int push(SSTAck_t **stack_pointer, unsigned int line_number)
{
	(void)stack_pointer;
	(void)line_number;

	return (EXIT_SUCCESS);
}
