#ifndef BASE_STRUCTS_H
#define BASE_STRUCTS_H

#include "string_data.h"

/**
 * struct SSTAck_t - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct SSTAck_t
{
	int n;
	struct SSTAck_t *prev;
	struct SSTAck_t *next;
} SSTAck_t;

/**
* struct instruct_s - doubly-linked list of all the opcodes
* @opcode: the opcode
* @f: function to handle the opcode
* Description: asdf
*/
typedef struct instruct_s
{
	char *opcode;
	void (*f)(SSTAck_t **stack_pointer, unsigned int line_number);
} instruct_t;

/**
 * struct CommandTable_s - Node of a hash table
 *
 * @key: name of the command
 * @value: function pointer to what it invokes
 * @next: A pointer to the next node of the List
 */
typedef struct CommandNode_s
{
    char *key;
    int (*f)(SSTAck_t **stack_pointer, unsigned int line_number);
    struct CommandNode_s *next;
} CommandNode_t;

/**
 * struct CommandTable_s - Hash table data structure
 *
 * @size: The size of the array
 * @array: An array of size @size
 * Each cell of this array is a pointer to the first node of a linked list,
 * because we want our HashTable to use a Chaining collision handling
 */
typedef struct CommandTable_s
{
     unsigned long int size;
     CommandNode_t **array;
} CommandTable_t;

/** TYPE ALIAS FOR THE FUNCTION POINTERS ON HASH TABLE */
typedef int (*Command)(SSTAck_t **stack_pointer, unsigned int line_number);

/** FUNCTIONS USED TO BUILD AND MANAGE THE COMMAND LOOKUP TABLE */
int create_command_table(CommandTable_t **table);
CommandTable_t *allocate_memory_for_table(unsigned long int size);
Command get_command(const CommandTable_t *table, const char *key);
int set_command(CommandTable_t *table, const char *key, Command func);
unsigned long int hash_djb2(const unsigned char *str);
unsigned long int key_index(const unsigned char *key, unsigned long int size);
void free_command_table(CommandTable_t *table);

int initialize_stack(SSTAck_t **stack_pointer);

/* FUNCTIONS DEFINING THE BEHAVIOUR OF SPECIFIC OPCODES */
int push(SSTAck_t **stack_pointer, unsigned int line_number);
int pall(SSTAck_t **stack_pointer, unsigned int line_number);
int pint(SSTAck_t **stack_pointer, unsigned int line_number);
int pop(SSTAck_t **stack_pointer, unsigned int line_number);
int swap(SSTAck_t **stack_pointer, unsigned int line_number);
int add(SSTAck_t **stack_pointer, unsigned int line_number);
int nop(SSTAck_t **stack_pointer, unsigned int line_number);

void absolute_pop(SSTAck_t **stack_pointer);
int absolute_push(SSTAck_t **stack_pointer, int number);

#endif 
