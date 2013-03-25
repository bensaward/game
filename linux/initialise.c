#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <main.h>

void init_coords (void)
{
  coordinate_x=init_coordinate_x;
  coordinate_y=init_coordinate_y;
}

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
