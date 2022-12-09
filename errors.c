#include "simple_shell.h"

void throw_error(SimpleShell_t **shell)
{
    char specific_error[20];
    char error_message[255];

    if ((*shell)->error_num == 1)
        snprintf(specific_error, 20, "%s", "Permission denied\n");
    else if ((*shell)->error_num == 2)
        snprintf(specific_error, 20, "%s", "not found\n");
    else if ((*shell)->error_num == 3)
        snprintf(specific_error, 20, "%s", "Can't open\n");
    else
        snprintf(specific_error, 20, "%s", "Unknown Error\n");

    snprintf(
        error_message,
        255,
        "%s: %d: %s: %s",
        _getenv((*shell)->enviornment, "_"),
        (*shell)->line_num,
        (*shell)->command_args[0],
        specific_error
    );

    fprintf(stderr, "%s", error_message);
}
