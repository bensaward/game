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


void print_n_xml(char *file_path, int buffer_size)
{
  system("clear");
  FILE *xml;
  char buffer[buffer_size];
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

void clean_terminal(void)
{
  for (int i=4; i<array_width; i++)
  {
    printf("\033[%d;%dH ", array_height+3, i);
  }
}

void sprint_terminal(char* to_print, int size)
{
  int char_number;
  int number_buffers=size/(array_width-7), char_left_over=size%(array_width-7);

  if(size>(array_width-4))
  {
    for (int i=0; i<number_buffers; i++)
    {
      clean_terminal();
      char_number=i*(array_width-7);
      for(int x=4; x<array_width-3; x++)
      {
	printf("\033[%d;%dH%c", array_height+3, x, to_print[char_number]);
	char_number++;
      }
      printf("\033[%d;%dH...", array_height+3, array_width-3);
      int key_pressed=getch();
      wait_for_enter(key_pressed);
    }

    clean_terminal();
    for (int i=0; i<char_left_over; i++)
    {
      printf("\033[%d;%dH%c", array_height+3, i+4, to_print[char_number]);
      char_number++;
    }
    int key_pressed=getch();
    wait_for_enter(key_pressed);
  }
  else
  {
    clean_terminal();
    for (int i=0; i<size; i++)
    {
      printf("\033[%d;%dH%c", array_height+3, i+4, to_print[i]);
    }
  }
}

void sprint_tok_terminal(char* to_print, int size)
{
  clean_terminal();
  char token[size/2][16];
  char *result;
  int buffer_number, total_chars=0, token_number=0, token_size[size/2], print_head=4, char_remaining, end_tok;

  result=strtok(to_print, " ");
  while (total_chars+strlen(result) <= size) //successfully debugged
  {
    strncpy(token[token_number], result, sizeof(token[token_number]));
    token_size[token_number]=(strlen(token[token_number])+1); //+1 for space
    total_chars+=token_size[token_number];
    if (total_chars >= size)
    {
        break;
    }
    else
    {
        result=strtok(NULL, " "); //increment pointer
        token_number++;
    }

  }
  //getch();

 if (total_chars<=(array_width-3))
  {
    for (int i=0; i<token_number; i++)
    {
      printf("\033[%d;%dH%s", array_height+3, print_head, token[i]);
      print_head+=token_size[i];
    }
  }
  else
  {
    int word_number=0;
    while (word_number<token_number)
    {
      clean_terminal();
      print_head=4;
      end_tok=(3+token_size[word_number]);
      while (end_tok <=(array_width-3))
      {
        printf("\033[%d;%dH%s", array_height+3, print_head, token[word_number]);
        print_head+=token_size[word_number];
        word_number++;
        if (word_number>token_number) {break;}
        else{end_tok+=token_size[word_number];}
      }
      printf("\033[%d;%dH...", array_height+3, array_width-3);
      int key_caught=getch();
      wait_for_enter(key_caught);
    }
  }
}
