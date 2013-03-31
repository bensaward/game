#include <launcher_src/launcher.h>
#include <main.h>
#include <gtk/gtk.h>

void init_window(int argc, char *argv[])
{
  gtk_init(&argc, &argv);
  launcher=gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(launcher), game_name);
  gtk_window_set_position(GTK_WINDOW(launcher), GTK_WIN_POS_CENTER);
  gtk_window_set_default_size(GTK_WINDOW(launcher), launcher_width, launcher_height);
  launcher_container=gtk_fixed_new();
  gtk_container_add(GTK_CONTAINER(launcher), launcher_container);
  g_signal_connect_swapped(G_OBJECT(launcher), "destroy", G_CALLBACK(gtk_main_quit), NULL);
}

void button_init(void)
{
  play_button=gtk_button_new_with_label("Play!");
  gtk_widget_set_size_request(play_button, button_width, button_height);
  gtk_fixed_put(GTK_FIXED(launcher_container), play_button, (launcher_width/2)-(button_width/2), (launcher_height/2)-(button_height/2));
  g_signal_connect_swapped(play_button, "clicked", G_CALLBACK(exec_gnome_terminal), NULL);
}
  