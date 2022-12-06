#include "simple_shell.h"

int main(int argc, char *argv[])
{
    SimpleShell_t *shell;
    UserInterface_t *repl;
    ScriptReader_t *script;

    int is_interactive = FALSE;
    int exit_status = EXIT_SUCCESS;

    create_simple_shell(&shell);

    is_interactive = isatty(STDIN_FILENO);

    if (is_interactive)
    {
        create_user_interface(&repl);
        exit_status = open_repl(&repl);
    }
    else
    {  
        create_script_reader(&script);
        exit_status = interpret_script(&script);
    }
    free_simple_shell(&shell);

    return (exit_status);
}