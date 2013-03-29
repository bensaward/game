#include <main.h>
#include <launcher_src/launcher.h>

void exec_gnome_terminal(void)
{
  snprintf(array_height_char, sizeof(array_height_char), "%d", array_height+10);
  snprintf(array_width_char, sizeof(array_width_char), "%d", array_width);
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

void game_play(void)
{
  gtk_widget_hide_all(launcher);
  exec_gnome_terminal();
}