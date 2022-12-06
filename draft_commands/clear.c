#include "simple_shell.h"

/**
 * FUNCTION TO EXECUTE A COMMAND WILL LOOK SOMETHING LIKE THIS:
 * - assume the CommandParser_t data structure will contain everything 
 * needed to execute the command. If you need something else we can
 * put it into the command parser.
 * - this is only the 'entry point' a kind of mini-main for that 
 * specific command. You should be able to have other functions defined 
 * if you absolutely have to.
*/
void clear_screen(CommandParser_t **parser)
{
    printf("\e[1;1H\e[2J");
    // printf("\033[2J\033[1;1H");
    // printf("\x1b[2J\x1b[1;1H");
    // these should both work if that one does not.
}