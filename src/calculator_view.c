#include <gtk/gtk.h>
#include "calculator_view.h"
#include "calculator_presenter.h"

struct CalculatorView {
  CalculatorPresenter *presenter;
  GtkWidget *win_calculator;
  GtkWidget *txt_result;
};

void btn_0_clicked_cb(GtkWidget *widget, gpointer data)
{
  CalculatorView *view = data;
  calculator_presenter_add_digit(view->presenter, '0');
}

void btn_1_clicked_cb(GtkWidget *widget, gpointer data)
{
  CalculatorView *view = data;
  calculator_presenter_add_digit(view->presenter, '1');
}

void btn_2_clicked_cb(GtkWidget *widget, gpointer data)
{
  CalculatorView *view = data;
  calculator_presenter_add_digit(view->presenter, '2');
}

void btn_3_clicked_cb(GtkWidget *widget, gpointer data)
{
  CalculatorView *view = data;
  calculator_presenter_add_digit(view->presenter, '3');
}

void btn_4_clicked_cb(GtkWidget *widget, gpointer data)
{
  CalculatorView *view = data;
  calculator_presenter_add_digit(view->presenter, '4');
}

void btn_5_clicked_cb(GtkWidget *widget, gpointer data)
{
  CalculatorView *view = data;
  calculator_presenter_add_digit(view->presenter, '5');
}

void btn_6_clicked_cb(GtkWidget *widget, gpointer data)
{
  CalculatorView *view = data;
  calculator_presenter_add_digit(view->presenter, '6');
}

void btn_7_clicked_cb(GtkWidget *widget, gpointer data)
{
  CalculatorView *view = data;
  calculator_presenter_add_digit(view->presenter, '7');
}

void btn_8_clicked_cb(GtkWidget *widget, gpointer data)
{
  CalculatorView *view = data;
  calculator_presenter_add_digit(view->presenter, '8');
}

void btn_9_clicked_cb(GtkWidget *widget, gpointer data)
{
  CalculatorView *view = data;
  calculator_presenter_add_digit(view->presenter, '9');
}

void btn_point_clicked_cb(GtkWidget *widget, gpointer data)
{
  CalculatorView *view = data;
  calculator_presenter_add_point(view->presenter);
}

void btn_result_clicked_cb(GtkWidget *widget, gpointer data)
{
  CalculatorView *view = data;
  calculator_presenter_compute(view->presenter);
}

void btn_clear_clicked_cb(GtkWidget *widget, gpointer data)
{
  CalculatorView *view = data;
  calculator_presenter_clear(view->presenter);
}

void btn_back_clicked_cb(GtkWidget *widget, gpointer data)
{
  CalculatorView *view = data;
  calculator_presenter_back(view->presenter);
}

void btn_division_clicked_cb(GtkWidget *widget, gpointer data)
{
  CalculatorView *view = data;
  calculator_presenter_set_operator(view->presenter, Division);
}

void btn_multiplication_clicked_cb(GtkWidget *widget, gpointer data)
{
  CalculatorView *view = data;
  calculator_presenter_set_operator(view->presenter, Multiplication);
}

void btn_subtraction_clicked_cb(GtkWidget *widget, gpointer data)
{
  CalculatorView *view = data;
  calculator_presenter_set_operator(view->presenter, Subtraction);
}

void btn_addition_clicked_cb(GtkWidget *widget, gpointer data)
{
  CalculatorView *view = data;
  calculator_presenter_set_operator(view->presenter, Addition);
}

void win_calculator_destroy_cb(GtkWidget *widget, gpointer data)
{
  gtk_main_quit();

  CalculatorView *view = data;
  calculator_view_free(view);
}

CalculatorView *calculator_view_new()
{
  CalculatorView *view = malloc(sizeof(CalculatorView));
  CalculatorPresenter *presenter = calculator_presenter_new(view);

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
  gtk_builder_connect_signals(builder, view);
  g_object_unref(G_OBJECT(builder));

  view->presenter = presenter;
  view->win_calculator = GTK_WIDGET(win_calculator);
  view->txt_result = GTK_WIDGET(txt_result);

  calculator_view_result_changed(view, "0");

  return view;
}

void calculator_view_free(CalculatorView *view)
{
  calculator_presenter_free(view->presenter);
  free(view);
}

void calculator_view_show(CalculatorView *view)
{
  gtk_widget_show(view->win_calculator);
}

void calculator_view_result_changed(CalculatorView *view, const char *result)
{
  GtkEntry *entry = GTK_ENTRY(view->txt_result);
  gtk_entry_set_text(entry, result);
}
