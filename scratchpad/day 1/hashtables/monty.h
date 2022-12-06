#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string.h>

#define DELIMS " \n\t\a\b"

/* MAKE SURE THESE ARE KEPT UPDATED AND MATCH! */
#define NUM_OF_OPS 7
#define NAME_BUFFER_SIZE 5
#define OPCODE_NAMES {"push", "pall", "pint", "pop", "swap", "nop", "add"}
#define FUNCTIONS {push, pall, pint, pop, swap, nop, add}

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
* struct instruct_s - doubly-linked list of all the opcodes
* @opcode: the opcode
* @f: function to handle the opcode
* Description: asdf
*/
typedef struct instruct_s
{
	char *opcode;
	void (*f)(stack_t **stack_pointer, unsigned int line_number);
} instruct_t;

/* FUNCTIONS DEFINING THE BEHAVIOUR OF SPECIFIC OPCODES */
void push(stack_t **stack_pointer, unsigned int line_number);
void pall(stack_t **stack_pointer, unsigned int line_number);
void pint(stack_t **stack_pointer, unsigned int line_number);
void pop(stack_t **stack_pointer, unsigned int line_number);
void swap(stack_t **stack_pointer, unsigned int line_number);
void add(stack_t **stack_pointer, unsigned int line_number);
void nop(stack_t **stack_pointer, unsigned int line_number);

#endif
