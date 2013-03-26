#include <launcher_src/launcher.h>
#include <gtk/gtk.h>

void init_window(int argc, char *argv[])
{
  GtkWidget *window;
  gtk_init(&argc, &argv);
  window=gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_widget_show(window);
  gtk_main();
}