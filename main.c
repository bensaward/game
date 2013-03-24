#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include </home/ben/code/game/main.h>

/* 
 * See main.h for defining array size etc
 * Functions are found in various *.c files
 */

int main()
{
  init_coords();
  draw_screen();
  int character_pressed;
  get_config();
  
  for(;;)
  {
    character_pressed=getch();
    update_coords(character_pressed);
    redraw_screen();
  }
}