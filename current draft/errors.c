#include "simple_shell.h"
/**
 * errors - prints error messages
 * @token - command that failed
 * @argument - error of command
 * Return: void
*/
void errors(char *token, char *argument __attribute__((unused)))
{
    char *message = "command not found";
    char *st = NULL;
    int i;

    st = calloc(200, sizeof(char));

    strcat(st, token);
    strcat(st, ": ");
    strcat(st, message);
    strcat(st, "\n");

    for (i = 0; st[i] != '\0'; i++)
        ;
    write(STDERR_FILENO, &st[i], 1);
    free(st);
}