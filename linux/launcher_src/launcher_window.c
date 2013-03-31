#include <main.h>
#include <launcher_src/launcher.h>

void exec_gnome_terminal(void)
{
  gtk_main_quit();
  snprintf(array_height_char, sizeof(array_height_char), "%d", array_height+10);
  snprintf(array_width_char, sizeof(array_width_char), "%d", array_width);
  getcwd(cwd, sizeof(cwd));
  char game_file[]="/game";
  strncat(cwd, game_file, sizeof(cwd));
  strncat(geometry, array_width_char, sizeof(geometry));
  strncat(geometry, "x", sizeof(geometry));
  strncat(geometry, array_height_char, sizeof(geometry));
  execlp("xterm", "-e", cwd, "-geometry", geometry, (char *) 0);
}
