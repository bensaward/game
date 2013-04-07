#ifndef _CONSOLE_INTERPRETER_H_
#define _CONSOLE_INTERPRETER_H_

int arg_count;

void escape_to_terminal(void);
void interpret_args (char arguments[][16], int argument_number);
void interpret_arg (char* argument);


#endif