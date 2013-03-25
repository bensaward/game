#ifndef array_width
#define array_width 40
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

#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include <string.h>
#include <stdlib.h>

char up_key, down_key, left_key, right_key, cursor_char;   // Globals here
unsigned short char_printed;
int old_x, old_y, coordinate_x, character_pressed, coordinate_y, cursor_y;

void init_coords(void);  // functions from initialise.c here
void get_config(void);
void update_coords(int key);

void print_menu();  // functions from print.c here
void update_cursor(int pressed);
void print(int x, int y);
void print_to_screen();
void redraw_screen();
void draw_screen();
int getch (void);
int extended_key(int pressed);

int rand_int(unsigned int min, unsigned int max); // functions from prng.c here

void loop_campaign(); // functions from loops.c here
void loop_menu();

#endif
