#ifndef STACK_H
#define STACK_H

/**
 * struct SSSTAck_t - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct SSSTAck_t
{
	int n;
	struct SSSTAck_t *prev;
	struct SSSTAck_t *next;
} SSTAck_t;

void free_stack(SSTAck_t **stack_pointer);
int initalize_stack(SSTAck_t **stack_pointer);

#endif
