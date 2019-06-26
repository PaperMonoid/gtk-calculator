#include <gtk/gtk.h>

void btn_click_me_clicked_cb(GtkWidget *widget, gpointer data)
{
  g_print ("Hello World\n");
}

int main(int argc, char *argv[])
{
  GtkBuilder *builder;
  GObject *window;
  GObject *button;
  GError *error = NULL;

  gtk_init(&argc, &argv);

  /* Construct a GtkBuilder instance and load our UI description */
  builder = gtk_builder_new();
  if (gtk_builder_add_from_file(builder, "views/calculator_window.glade", &error) == 0) {
    g_printerr ("Error loading file: %s\n", error->message);
    g_clear_error(&error);
    return 1;
  }

  /* Connect signal handlers to the constructed widgets. */
  window = gtk_builder_get_object(builder, "calculator_window");
  gtk_builder_connect_signals(builder, NULL);

  /* Clear memory */
  g_object_unref(G_OBJECT(builder));

  /* Show and run UI */
  gtk_widget_show(GTK_WIDGET(window));
  gtk_main();

  return 0;
}
