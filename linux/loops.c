#include <main.h>
#include <string.h>
#include <launcher_src/launcher.h>
#include <console_interpreter.h>

void loop_campaign(char* name)
{
  intro_loop(name);
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

void loop_campaign_menu()
{
  char menu_items[2][16]={"Regular", "Fantasy"};
  system("clear");
  int print_height=2, total_menu_items=0;
  for (int i=0; i<2; i++)
  {
    printf("\033[%d;%dH%s", print_height, (array_width-strlen(menu_items[i]))/2, menu_items[i]);
    total_menu_items++;
    print_height+=2;
  }
  print_height=2;
  printf("\033[2;%dH%c", array_width, cursor_char);
  for (;;)
  {
    character_pressed=getch();
    switch (character_pressed)
    {
      case arrow_down:
      {
	if (print_height != total_menu_items*2)
	{
	  int old_height=print_height;
	  print_height+=2;
	  printf("\033[%d;%dH ", old_height, array_width);
	  printf("\033[%d;%dH%c", print_height, array_width, cursor_char);
	  break;
	}
	else
	{
	  printf("\a");
	  break;
	}
      }
      
      case arrow_up:
      {
	if (print_height != 2)
	{
	  int old_height=print_height;
	  print_height-=2;
	  printf("\033[%d;%dH ", old_height, array_width);
	  printf("\033[%d;%dH%c", print_height, array_width, cursor_char);
	  break;
	}
	else
	{
	  printf("\a");
	  break;
	}
      }
      
      case enter_key:
      {
	loop_campaign(menu_items[(print_height/2)-1]);
      }
    }
  }
}

void intro_loop(char *campaign)
{
  if (strncmp(campaign, "Regular", sizeof(campaign))==0)
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
  else
  {
    system("clear");
    printf("\033[1;1H");
    puts("This feature is coming soon!\n\nPress any key to return...");
    int key_pressed=getch();
    loop_campaign_menu();
  }
}
    
    