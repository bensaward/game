#include <main.h>
#include <unistd.h>
#include <main.h>
#include <launcher.h>

int main()
{
  char array_height_char[3], array_width_char[3];
  snprintf(array_height_char, sizeof(array_height_char), "%d", array_height+10);
  snprintf(array_width_char, sizeof(array_width_char), "%d", array_width);
  char cwd[100];
  getcwd(cwd, sizeof(cwd));
  char game_file[]="/game";
  strncat(cwd, game_file, sizeof(cwd));
  char command[1024]="gnome-terminal --geometry=";
  strncat(command, array_width_char, sizeof(command));
  strncat(command, "x", sizeof(command));
  strncat(command, array_height_char, sizeof(command));
  strncat(command, " -e ", sizeof(command));
  strncat(command, cwd, sizeof(command));
  system(command);
}