#ifndef array_width
#define array_width 60
#endif

#ifndef array_height
#define array_height 20
#endif

#ifndef init_coordinate_x
#define init_coordinate_x array_width/2
#endif

#ifndef init_coordinate_y
#define init_coordinate_y array_height/2
#endif

#ifndef arrow_up
#define arrow_up 65 //<-- bit of a bodge... corresponds to the last part of the sequence for down.
#endif //First 2 parts are ignored/discarded by getch(). Will only work on my pc/maybe most of Linux
// TODO: fix getch() or use similar function to capture all 3 parts of the key sequence

#ifndef arrow_down
#define arrow_down 66 //same story here but for up key
#endif

#ifndef enter_key
#define enter_key 10 //ascii for enter... I think...
#endif

#ifndef game_name
#define game_name "- Game Name Here -"
#endif

#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include <string.h>
#include <stdlib.h>

char up_key, down_key, left_key, right_key, cursor_char, *campaign_type;   // Globals here
unsigned short char_printed;
int old_x, old_y, coordinate_x, character_pressed, coordinate_y, cursor_y;

void init_coords(void);  // functions from initialise.c here
void get_config(void);

void print_menu();  // functions from print.c here
void print(int x, int y);
void redraw_screen();
void draw_screen();
void print_n_xml(char *file_path, int buffer_size);
void print_terminal();
void clean_terminal(void);
void sprint_terminal(char* buffer, int size);
void sprint_tok_terminal(char* to_print, int size);

void update_cursor(int pressed); //functions from keys.c here
int getch (void);
int extended_key(int pressed);
void update_coords(int key);
int wait_for_enter(int key);

int rand_int(unsigned int min, unsigned int max); // functions from prng.c here

void loop_campaign(char* name); // functions from loops.c here
void loop_menu();
void intro_loop(char *campaign);
void loop_campaign_menu();

#endif
