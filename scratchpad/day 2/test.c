#include "stringdata.h"

int main()
{
    char *filename = "test.c";
    ScriptBuffer_t *script = NULL;

    create_buffer(&script);

    load_script(&script, filename);

    list_script(&script);

    free_script(&script);

    return (0);
}
