#include <gtk/gtk.h>

void btn_0_clicked_cb(GtkWidget *widget, gpointer data)
{
  g_print ("0\n");
}

void btn_1_clicked_cb(GtkWidget *widget, gpointer data)
{
  g_print ("1\n");
}

void btn_2_clicked_cb(GtkWidget *widget, gpointer data)
{
  g_print ("2\n");
}

void btn_3_clicked_cb(GtkWidget *widget, gpointer data)
{
  g_print ("3\n");
}

void btn_4_clicked_cb(GtkWidget *widget, gpointer data)
{
  g_print ("4\n");
}

void btn_5_clicked_cb(GtkWidget *widget, gpointer data)
{
  g_print ("5\n");
}

void btn_6_clicked_cb(GtkWidget *widget, gpointer data)
{
  g_print ("6\n");
}

void btn_7_clicked_cb(GtkWidget *widget, gpointer data)
{
  g_print ("7\n");
}

void btn_8_clicked_cb(GtkWidget *widget, gpointer data)
{
  g_print ("8\n");
}

void btn_9_clicked_cb(GtkWidget *widget, gpointer data)
{
  g_print ("9\n");
}

void btn_point_clicked_cb(GtkWidget *widget, gpointer data)
{
  g_print ("point\n");
}

void btn_result_clicked_cb(GtkWidget *widget, gpointer data)
{
  g_print ("result\n");
}

void btn_clear_clicked_cb(GtkWidget *widget, gpointer data)
{
  g_print ("clear\n");
}

void btn_back_clicked_cb(GtkWidget *widget, gpointer data)
{
  g_print ("back\n");
}

void btn_division_clicked_cb(GtkWidget *widget, gpointer data)
{
  g_print ("division\n");
}

void btn_multiplication_clicked_cb(GtkWidget *widget, gpointer data)
{
  g_print ("multiplication\n");
}

void btn_subtraction_clicked_cb(GtkWidget *widget, gpointer data)
{
  g_print ("subtraction\n");
}

void btn_addition_clicked_cb(GtkWidget *widget, gpointer data)
{
  g_print ("addition\n");
}

GtkWidget* calculator_view_new()
{
  GtkBuilder *builder;

  GObject *window;
  GObject *button;
  GError *error = NULL;

  builder = gtk_builder_new();

  if (gtk_builder_add_from_file(builder, "views/calculator_window.glade", &error) == 0) {
    g_printerr ("Error loading file: %s\n", error->message);
    g_clear_error(&error);
    return NULL;
  }

  window = gtk_builder_get_object(builder, "calculator_window");
  gtk_builder_connect_signals(builder, NULL);

  g_object_unref(G_OBJECT(builder));

  return GTK_WIDGET(window);
}
