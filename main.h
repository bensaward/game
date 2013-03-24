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

#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include <string.h>
#include <stdlib.h>

char up_key, down_key, left_key, right_key;
unsigned short char_printed;
int old_x, old_y, coordinate_x, coordinate_y;

void init_coords(void);
void get_config(void);
void update_coords(int key);
void print(int x, int y);
void print_to_screen();
void redraw_screen();
void draw_screen();
void get_config(void);
int getch (void);
int rand_int(unsigned int min, unsigned int max);

#endif
