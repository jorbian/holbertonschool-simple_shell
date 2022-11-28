#ifndef ERRORS_H
#define ERRORS_H


/* DEFINITIONS OF ERRORS AND THE ERROR HANDLIJG ROUTINE(S) */
#define ERROR_FLAG 2147483647 /* NUMBER ON TOP OF STACK TO TRIGGER EXIT */
#define BAD_INPUT "USAGE: monty file\n"
#define BAD_FILE "Error: Can't open file %s\n"
#define COULDNT_MALLOC "Error: malloc failed\n"
#define BAD_INSTRUCTION "L%d: unknown instruction %s\n"
#define CANT_PUSH "L%d: usage: push integer\n"
#define CANT_PINT "L%d: can't pint, stack empty\n"
#define CANT_POP "L%d: can't pop an empty stack\n"
#define CANT_SWAP "L%d: can't swap, stack too short\n"
#define CANT_ADD "L%d: can't add, stack too short\n"
#define UNKNOWN "Unknown error\n"

/* OUR ONE AND ONLY ERROR HANDLING ROUTINE */
int throw_error(char *message, int line, char *string);

#endif
