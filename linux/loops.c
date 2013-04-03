#include <main.h>
#include <string.h>
#include <launcher_src/launcher.h>

void loop_campaign()
{
  char *campaign_type="regular";
  intro_loop(campaign_type);
  init_coords();
  draw_screen();
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
  print_menu();
  for(;;)
  {
    character_pressed=getch();
    update_cursor(character_pressed);
  }
}

void intro_loop(char *campaign)
{
  if (strncmp(campaign, "regular", sizeof(campaign))==0)
  {
    int paused;
    int number_xml=3;
    getcwd(cwd, sizeof(cwd));
    strncat(cwd, "/../xml/", sizeof(cwd));
    char file_names[3][16]={"0.xml", "1.xml", "2.xml"};
    char file_address[3][128];
    for (int i=0; i<number_xml; i++)
    {
      strncpy(file_address[i], cwd, sizeof(file_address[i]));
      strncat(file_address[i], file_names[i], sizeof(file_address[i]));
    }
    print_n_xml(file_address[0], array_width);
    print_terminal();
    char terminal_text[]="There was once a sword, used by a great king to banish the foes from his kingdom and smite his enemies in the battlefield. Rumour has it that the sword glows bright blue.";
    sprint_tok_terminal(terminal_text, strlen(terminal_text));
    paused=getch();
    wait_for_enter(paused);
  }
}
    
    