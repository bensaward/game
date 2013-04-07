#include <console_interpreter.h>
#include <stdio.h>
#include <string.h>
#include <main.h>

void escape_to_terminal(void)
{
  clean_terminal();
  arg_count=0;
  char entered_commands[256], *argument, *newline;
  char error_msg[]="Argument exceeded the accepted size of 15 letters";
  char *condition;
  
  printf("\033[%d;4H", array_height+3);
  fgets(entered_commands, sizeof(entered_commands), stdin);
  char entered_commands_cpy_1[strlen(entered_commands)], entered_commands_cpy_2[strlen(entered_commands)], entered_commands_cpy_3[strlen(entered_commands)], entered_commands_cpy_4[strlen(entered_commands)];
  strncpy(entered_commands_cpy_1, entered_commands, sizeof(entered_commands_cpy_1));
  newline=strchr(entered_commands, '\n');
  
  if (newline != NULL)
  {
    entered_commands_cpy_1[newline-entered_commands]='\0';
  }
  
  strncpy(entered_commands_cpy_2, entered_commands_cpy_1, sizeof(entered_commands_cpy_2));
  strncpy(entered_commands_cpy_3, entered_commands_cpy_1, sizeof(entered_commands_cpy_3));
  strncpy(entered_commands_cpy_4, entered_commands_cpy_1, sizeof(entered_commands_cpy_4));
  
  condition=strchr(entered_commands_cpy_2, ' ');
  if (condition != NULL)
  {
    argument=strtok(entered_commands_cpy_3, " ");
    while (argument != NULL)
    {
      arg_count++;
      argument=strtok(NULL, " ");
    }

    char argument_array[arg_count][16];
    argument=strtok(entered_commands_cpy_4, " ");
  
    for (int i=0; i<arg_count; i++)
    {
      if (strlen(argument) < 16)
      {
        strncpy(argument_array[i], argument, sizeof(argument_array[i]));
      }
      else
      {
        sprint_tok_terminal(error_msg, sizeof(error_msg));
        break;
      }
      argument=strtok(NULL, " ");
    }
    interpret_args(argument_array, arg_count);
  }
  
  else
  {
    char argument_array[16];
    if (strlen(entered_commands) < 16)
    {
      strncpy(argument_array, entered_commands, sizeof(argument_array));
    }
    else
    {
      sprint_tok_terminal(error_msg, sizeof(error_msg));
    }
    interpret_arg (argument_array);
  }
}

void interpret_args ( char arguments[][16], int argument_number)
{
  char interpreter_unrecognised[200]= "Sorry I did not recognise the words: ";
  int quit;
  
  for (int i=0; i<argument_number; i++)
  {
   quit=strncmp(arguments[i], "quit", sizeof(arguments[i]));
   
   if (quit == 0)
   {
     exit(0);
   }
   
   else
   {
     strncat(interpreter_unrecognised, arguments[i], sizeof(interpreter_unrecognised));
     strncat(interpreter_unrecognised, " ", sizeof(interpreter_unrecognised));
   }
  }
  sprint_tok_terminal(interpreter_unrecognised, strlen(interpreter_unrecognised));
}

void interpret_arg ( char *arguments)
{
  char interpreter_unrecognised[100]="Sorry I did not recognise the word: ";
  int quit;
  
  quit=strncmp(arguments, "quit", sizeof(arguments));
   
  if (quit == 0)
  {
    exit(0);
  }
   
  else
  {
    strncat(interpreter_unrecognised, arguments, sizeof(interpreter_unrecognised));
    sprint_tok_terminal(interpreter_unrecognised, strlen(interpreter_unrecognised));
  }
   
}
