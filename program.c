#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

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
char up_key, down_key, left_key, right_key;

void get_config (void)
{
  char *username;
  username=getlogin();
  char file_address[100]="/home/", file_name[]="/.game/config.txt";
  strncat(file_address, username, sizeof(file_address));
  strncat(file_address, file_name, sizeof(file_address));
  FILE *config;
  char buffer[1000];
  config = fopen(file_address, "rt");
  if (config==NULL)
  {
    printf("\033[%d;1HError opening config file", array_height+10);
    exit(1);
  }
  else
  {
    while(fgets(buffer, sizeof(buffer), config) != NULL)
    {
      char token1[20], token2[10];
      sscanf(buffer, "%s %[^, ]%*[ ]%s", token1, token2);
      if(strncmp(token1, "up", sizeof(token1)) == 0)
      {
	up_key=token2[0];
      }
      
      if (strncmp(token1, "down", sizeof(token1)) == 0)
      {
	down_key=token2[0];
      }
      
      if (strncmp(token1, "right", sizeof(token1)) == 0)
      {
	right_key=token2[0];
      }
      
      if (strncmp(token1, "left", sizeof(token1)) == 0)
      {
	left_key=token2[0];	
      }  
    }
    fclose(config);
  }
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

int main ()
{
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