#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include </home/ben/code/game/main.h>

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
  
}

void redraw_menu()
{
  
}