#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <main.h>
#include <pwd.h>

void init_coords (void)
{
  coordinate_x=init_coordinate_x;
  coordinate_y=init_coordinate_y;
}

void get_config (void)
{
  char *username=getlogin();
  if (username == NULL)
  {
      struct passwd *pass;
      pass=getpwuid(getuid());
      username=pass->pw_name;
  }
  printf("getlogin: %s\n", username);
  char file_address[100];
  strcpy(file_address, "/home/");
  printf("%s\n", file_address);
  strcat(file_address, username);
  printf("%s\n", file_address);
  strcat(file_address, "/.game/config.txt");
  printf("%s\n", file_address);

  //strcat(file_address, file_name);
  //printf("%s\n", file_address);
  FILE *config;
  char buffer[100];
  config = fopen(file_address, "r");
  if (config==NULL)
  {
    printf("\033[%d;1HError opening config file", array_height+10);
    exit(1);
  }
  else
  {
    while(fgets(buffer, sizeof(buffer), config) != NULL)
    {
      char token1[20], token2;
      sscanf(buffer, "%s %c", token1, token2);
      if(strcmp(token1, "up") == 0)
      {
        up_key=token2;
      }

      if (strcmp(token1, "down") == 0)
      {
        down_key=token2;
      }

      if (strcmp(token1, "right") == 0)
      {
        right_key=token2;
      }

      if (strcmp(token1, "left") == 0)
      {
        left_key=token2;
      }
    }
    fclose(config);
  }
}
