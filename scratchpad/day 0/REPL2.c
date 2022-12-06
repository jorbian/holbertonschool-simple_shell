#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string.h>

#define MAX_INPUT_BUFF 255

void clear_screen();

int main()
{
    clear_screen();

    int repl_active = 1;
    int exit_status = 0;
    char user_input[MAX_INPUT_BUFF];
    char *prompt = "($) ";

    while (repl_active)
    {
        printf("%s", prompt);
        fgets(user_input, MAX_INPUT_BUFF, stdin);

        if (strlen(user_input) > 1)
        {
            printf("BYE!!\n");
            repl_active = 0;
        }
    }
    return (exit_status);
}

void clear_screen()
{
    printf("\e[1;1H\e[2J");
}