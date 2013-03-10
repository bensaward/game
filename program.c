#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <string.h>

#define array_width 40
#define array_height 20

char* get_username(void);
void get_config(void);
void update_coords(int key);
void print(int x, int y);
void redraw_screen();
void draw_screen();

unsigned short char_printed;
int coordinate_x=array_width/2, coordinate_y=array_height/2, coordinate_height=0; /* defaults for spawn in top left of array at layer 0 */
int old_x, old_y;

void get_config (void)
{
  char *username;
  username=getlogin();
  puts(username);
  username="ben";
  char file_address[strlen(username)+6+17+1];
  strcat(file_address, "/home/");
  strcat(file_address, username);
  strcat(file_address, "/.game/config.txt");
  printf("%c", file_address);
}
  
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
  
  switch (key)
  {
    case 'w':
      if(coordinate_y==1)
      {
	break;
      }
      else
      {
	coordinate_y--;
	break;
      }
    
    case 'a': 
      if (coordinate_x==1)
      {
	break;	
      }
      else
      {
	coordinate_x--;
	break;
      }

    case 's':
      if (coordinate_y==array_height)
      {
	break;	
      }
      else
      {
	coordinate_y++;
	break;
      }

    case 'd':
      if (coordinate_x==array_width)
      {
	break;
      }
      else
      {
	coordinate_x++;
	break;
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

int main ()
{
  //draw_screen();
  //int character_pressed;
  get_config();
  
  for(;;)
  {
    //character_pressed=getch();
    //update_coords(character_pressed);
    //redraw_screen();
  }
}