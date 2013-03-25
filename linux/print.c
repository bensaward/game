#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <main.h>

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
}

void print(int x, int y)
{
  char printed;
  if(x==coordinate_x)
  {
    if(y==coordinate_y)
    {
      char_printed=1;
      printed='@';      
    }
    else
    {
      printed='.';  
    } 
  }
  else
  {
    printed='.';
  }
  if(x==array_width)
  {
    printf("%c\n", printed); 
  }
  else
  {
    printf("%c", printed);
  }
}

void redraw_screen ()
{
  char dot='.', at='@';
  printf("\033[%d;%dH%c", old_y, old_x, dot);
  printf("\033[%d;%dH%c", coordinate_y, coordinate_x, at);
  printf("\033[%d;4H", array_height+3);
}

void draw_screen ()
{
  system("clear");
  for (int y=1; y<=array_height; y++)
  {
    for (int x=1; x<=array_width; x++)
    {
      print(x, y);
      
    }
  }
  printf("\n");
  for (int x=0; x<array_width; x++)
  {
    printf("\033[%d;%dH-", array_height+2, x);
    printf("\033[%d;%dH-", array_height+4, x);   
  }
  printf("\033[%d;1H>> ", array_height+3);  
}

void print_menu()
{
  cursor_y=2;
  system("clear");
  char *campaign_text="Campaign";
  char *options_text="Options";
  char *exit_text="Exit";
  printf("\033[2;%dH%s", (array_width-sizeof(campaign_text))/2, campaign_text);
  printf("\033[4;%dH%s", (array_width-sizeof(options_text))/2, options_text);
  printf("\033[6;%dH%s", (array_width-sizeof(exit_text))/2, exit_text);
  printf("\033[%d;%dH%c", cursor_y, array_width-1, cursor_char);
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
	  loop_campaign();
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