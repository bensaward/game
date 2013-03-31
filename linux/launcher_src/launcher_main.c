#include <main.h>
#include <unistd.h>
#include <main.h>
#include <launcher_src/launcher.h>


int main(int argc, char *argv[])
{
  init_window(argc, argv);
  button_init();
  gtk_widget_show_all(launcher);
  gtk_main();
  exit(0);
}