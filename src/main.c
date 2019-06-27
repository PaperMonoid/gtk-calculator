#include <gtk/gtk.h>
#include "calculator_view.h"

int main(int argc, char *argv[])
{
  CalculatorView *view;

  gtk_init(&argc, &argv);
  view = calculator_view_new();
  calculator_view_show(view);
  gtk_main();

  return 0;
}
