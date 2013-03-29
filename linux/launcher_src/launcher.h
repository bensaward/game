#ifndef launcher_height
#define launcher_height 200
#endif

#ifndef launcher_width
#define launcher_width 400
#endif

#ifndef _LAUNCHER_H_
#define _LAUNCHER_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <gtk/gtk.h>

//global vars
char array_height_char[3], array_width_char[3], cwd[100];
GtkWidget *launcher;
GtkWidget *play_button;
GtkWidget *launcher_container;

//from launcher_window.c
void exec_gnome_terminal(void);
void game_play(void);

//from initialise.c
void init_window(int argc, char *argv[]);
void button_init(void);

#endif

