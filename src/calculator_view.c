#include <gtk/gtk.h>
#include "calculator_view.h"

void btn_0_clicked_cb(GtkWidget *widget, gpointer data)
{
  g_print("0\n");
}

void btn_1_clicked_cb(GtkWidget *widget, gpointer data)
{
  g_print("1\n");
}

void btn_2_clicked_cb(GtkWidget *widget, gpointer data)
{
  g_print("2\n");
}

void btn_3_clicked_cb(GtkWidget *widget, gpointer data)
{
  g_print("3\n");
}

void btn_4_clicked_cb(GtkWidget *widget, gpointer data)
{
  g_print("4\n");
}

void btn_5_clicked_cb(GtkWidget *widget, gpointer data)
{
  g_print("5\n");
}

void btn_6_clicked_cb(GtkWidget *widget, gpointer data)
{
  g_print("6\n");
}

void btn_7_clicked_cb(GtkWidget *widget, gpointer data)
{
  g_print("7\n");
}

void btn_8_clicked_cb(GtkWidget *widget, gpointer data)
{
  g_print("8\n");
}

void btn_9_clicked_cb(GtkWidget *widget, gpointer data)
{
  g_print("9\n");
}

void btn_point_clicked_cb(GtkWidget *widget, gpointer data)
{
  g_print("point\n");
}

void btn_result_clicked_cb(GtkWidget *widget, gpointer data)
{
  g_print("result\n");
}

void btn_clear_clicked_cb(GtkWidget *widget, gpointer data)
{
  g_print("clear\n");
}

void btn_back_clicked_cb(GtkWidget *widget, gpointer data)
{
  g_print("back\n");
}

void btn_division_clicked_cb(GtkWidget *widget, gpointer data)
{
  g_print("division\n");
}

void btn_multiplication_clicked_cb(GtkWidget *widget, gpointer data)
{
  g_print("multiplication\n");
}

void btn_subtraction_clicked_cb(GtkWidget *widget, gpointer data)
{
  g_print("subtraction\n");
}

void btn_addition_clicked_cb(GtkWidget *widget, gpointer data)
{
  g_print("addition\n");
}

CalculatorView* calculator_view_new()
{
  CalculatorView *view = malloc(sizeof(CalculatorView));

  GtkBuilder *builder;
  GObject *win_calculator;
  GObject *txt_result;
  GError *error = NULL;

  builder = gtk_builder_new();

  if (gtk_builder_add_from_file(builder, "views/win_calculator.glade", &error) == 0) {
    g_printerr ("Error loading file: %s\n", error->message);
    g_clear_error(&error);
    return NULL;
  }

  win_calculator = gtk_builder_get_object(builder, "win_calculator");
  txt_result = gtk_builder_get_object(builder, "txt_result");
  gtk_builder_connect_signals(builder, NULL);
  g_object_unref(G_OBJECT(builder));

  view->win_calculator = GTK_WIDGET(win_calculator);
  view->txt_result = GTK_WIDGET(txt_result);

  return view;
}

void calculator_view_free(CalculatorView *view)
{
  free(view);
}

void calculator_view_show(CalculatorView *view)
{
  gtk_widget_show(view->win_calculator);
}

void calculator_view_result_changed(CalculatorView *view, const char *result)
{
  g_print("result changed");
}
