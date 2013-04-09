#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <main.h>
#include <console_interpreter.h>


int getch(void)
{
  struct termios oldattr, newattr;
  int ch;
  tcgetattr(STDIN_FILENO, &oldattr);
  newattr=oldattr;
  newattr.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &newattr);
  ch=getchar();
  tcsetattr(STDIN_FILENO, TCSANOW, &oldattr);
  return ch;
}

int get_ansi_key(int array[3])
{
  for (int x=0; x<3; x++)
  {
    array[x]=0;
  }
  struct termios oldattr, newattr;
  tcgetattr(STDIN_FILENO, &oldattr);
  newattr=oldattr;
  newattr.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &newattr);
  
  array[0]=getchar();
  int i=0;
  while ((array[i] != '\n') || (i != 3))
  {
    i++;
    array[i]=getchar();
  }
  tcsetattr(STDIN_FILENO, TCSANOW, &oldattr); 
}

void update_coords (int key)
{
  old_x=coordinate_x;
  old_y=coordinate_y;
  if (key==up_key)
  {
    if(coordinate_y!=1)
    {
      coordinate_y--;
    }
  }
  
  if(key==left_key)
  {   
    if (coordinate_x!=1)
    {
      coordinate_x--;  
    }
  }
  
  if(key==down_key)
  {
    if (coordinate_y!=array_height)
    {
      coordinate_y++;
    }
  }

  if(key==right_key)
  {
    if (coordinate_x!=array_width)
      {
	coordinate_x++;
      }    
  }
  
  if(key==27) //code for ESC
  {  //TODO: add escape key to the config file
    escape_to_terminal();
  }
}

void update_cursor(int pressed)
{
  int old_cursor_y=cursor_y;
  //printf("\033[10;1HKey_pressed=%d", pressed);                   //use for debuging getch() and similar functions
  //printf("\033[11;1HExtended_key=%d", extended_key(pressed));    //use for debuging getch() and similar functions
  switch (extended_key(pressed))
  {
    case arrow_up:
    {
      if (cursor_y!=2)
      {
	cursor_y-=2;
	break;
      }
      else
      {
	break;
      }
    }
    
    case arrow_down:
    {
      if (cursor_y!=6)
      {
	cursor_y+=2;
	break;
      }
      else
      {
	break;
      }
    }
   
    case enter_key:
    {
      switch(cursor_y)
      {
	case 2:
	  loop_campaign_menu();
	  break;
	  
	case 4:
	  system("clear");
	  printf("\033[1;1H");
	  printf("See ~/.game/config.txt for options!\nPress any key to return...");
	  getch();
	  loop_menu();
	  break;
	  
	case 6:
	  printf("\n\n");
	  exit(0);
      }
    }
  }
  printf("\033[%d;%dH%c", old_cursor_y, array_width-1, ' ');
  printf("\033[%d;%dH%c", cursor_y, array_width-1, cursor_char);
}

int extended_key(int pressed)
{
  return (pressed==0 || pressed==244) ? getch() : pressed;
}

int wait_for_enter(int key)
{
  switch(key)
  {
    case enter_key:
    {
      return 0;
      break;
    }
    
    default:
    {
      int pressed=getch();
      wait_for_enter(pressed);
      break;
    }
  }
}
