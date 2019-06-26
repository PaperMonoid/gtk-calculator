#include <gtk/gtk.h>
#include "calculator_view.c"

int main(int argc, char *argv[])
{
  GtkWidget *window;
  gtk_init(&argc, &argv);
  window = calculator_view_new();
  gtk_widget_show(window);
  gtk_main();

  return 0;
}
