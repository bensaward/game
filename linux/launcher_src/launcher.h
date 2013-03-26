#ifndef _LAUNCHER_H_
#define _LAUNCHER_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//global vars
char array_height_char[3], array_width_char[3], cwd[100];

//from main.c
void exec_gnome_terminal(void);

//from initialise.c
void init_window(int argc, char *argv[]);

#endif