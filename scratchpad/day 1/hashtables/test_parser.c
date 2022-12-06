#include "parser.h"

int main()
{
    int index;
    CommandParser_t *parser = NULL;
    stack_t *stack;
    char keys[NUM_OF_OPS][NAME_BUFFER_SIZE] = OPCODE_NAMES;

    create_command_parser(&parser);

    for (index = 0; index < NUM_OF_OPS; index++)
    {
        get_command((parser->table), keys[index])(&stack, 0);
    }

    free_parser(&parser);

    return (0);
}