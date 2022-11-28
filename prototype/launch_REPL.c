#include "oop_monty.h"

int main()
{
    int exit_status = 0;
    CommandParser_t *command_parser = NULL;
    SSTAck_t *stack_pointer = NULL;

    command_parser = malloc(sizeof(CommandParser_t));
    if (command_parser == NULL)
        return (throw_error(COULDNT_MALLOC, 0, ""));

    stack_pointer = malloc(sizeof(SSTAck_t));
    if (stack_pointer == NULL)
    {
        free_parser(&command_parser);
        return (throw_error(COULDNT_MALLOC, 0, ""));
    }

    exit_status = launch_REPL(&command_parser, &stack_pointer);

    free_parser(&command_parser);
    free_stack(&stack_pointer);

    return (exit_status);
}

/**
 * launch_REPL - open up the interpreter in interactive mode
 * @parser: pointer to the command parser
 * @stack: stack pointer
 * 
 * Return: The programs exit status, EXIT_FAILURE or EXIT_SUCESS
 */
int launch_REPL(CommandParser_t **parser, SSTAck_t **stack)
{
    int REPL_active = 1;
    
}
/**
 * clear_screen - exactly what it says on the tin
 */
void clear_screen()
{
    printf("\e[1;1H\e[2J");
}