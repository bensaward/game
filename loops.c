#include </home/ben/code/game/main.h>

void loop_campaign()
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

void loop_menu()
{
  
}