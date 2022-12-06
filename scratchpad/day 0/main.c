#include "monty.h"

int main(int argc, char *argv[])
{
    int exit_status = 0;
    CommandParser_t *command_parser = NULL;
    SSTAck_t *stack_pointer = NULL;

    if (argc != 2)
        return (throw_error(BAD_INPUT, 0, ""));

    command_parser = malloc(sizeof(CommandParser_t));
    if (command_parser == NULL)
        return (throw_error(COULDNT_MALLOC, 0, ""));

    stack_pointer = malloc(sizeof(SSTAck_t));
    if (stack_pointer == NULL)
        return (throw_error(COULDNT_MALLOC, 0, ""));

    exit_status = execute_script(&command_parser, &stack_pointer, argv[1]);

    free_parser(&command_parser);
    free_stack(&stack_pointer);

    return (exit_status);
}
