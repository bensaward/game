#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <main.h>


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
  print_terminal();
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


void print_n_xml(char *file_path, char *buffer, int buffer_size)
{
  FILE *xml;
  int line_count=1;
  xml=fopen(file_path, "rt");
  if(xml != NULL)
  {
    while(fgets(buffer, buffer_size, xml)!=NULL)
    {
     printf("\033[%d;1H%s", line_count, buffer);
     line_count++;
    }
  }
  else
  {
    printf("\033[%d;1HError in opening xml %s", array_height+10, file_path);
  }
}

void print_terminal(void)
{
  for (int x=0; x<array_width; x++)
  {
    printf("\033[%d;%dH-", array_height+2, x);
    printf("\033[%d;%dH-", array_height+4, x);   
  }
  printf("\033[%d;1H>> ", array_height+3);  
}