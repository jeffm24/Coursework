#define _SERVER_H_
#include "mygtksockets.h"
/*
 * Author: Jeff Mariconda
 * Class: CS-392
 *
 * Callback function for when the "Connect" button is clicked in the main client window.
 * Displays a popup window in which the use can enter the Server, Port, and Username that
 * they want to use to connect. 
 */
void connectclick_cb(GtkWidget *w, gpointer data)
{
  GtkWidget *connectWin;
  GtkWidget *mainTab;
  GtkWidget *label;
  GtkWidget *server_txt, *port_txt, *user_txt;
  GtkWidget *ok_btn, *cancel_btn;

  connectWin = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  g_signal_connect(G_OBJECT(connectWin), "delete_event", G_CALLBACK(closepopup_cb), (gpointer)w);
  g_signal_connect(G_OBJECT(connectWin), "destroy", G_CALLBACK(closepopup_cb), (gpointer)w);
  gtk_container_set_border_width(GTK_CONTAINER(connectWin), 10);
  gtk_window_set_title(GTK_WINDOW(connectWin), "Connect");

  mainTab = gtk_table_new(4, 4, FALSE); 
  gtk_container_add(GTK_CONTAINER(connectWin), mainTab);
  gtk_table_set_row_spacings((GtkTable*)mainTab, 5);
  gtk_table_set_col_spacings((GtkTable*)mainTab, 5);

  label = gtk_label_new("Server:");
  gtk_table_attach_defaults((GtkTable*)mainTab, label, 0, 1, 0, 1);
  gtk_widget_show(label);

  label = gtk_label_new("Port:");
  gtk_table_attach_defaults((GtkTable*)mainTab, label, 0, 1, 1, 2);
  gtk_widget_show(label);

  label = gtk_label_new("Username:");
  gtk_table_attach_defaults((GtkTable*)mainTab, label, 0, 1, 2, 3);
  gtk_widget_show(label);

  server_txt = gtk_text_view_new();
  gtk_table_attach_defaults((GtkTable*)mainTab, server_txt, 1, 4, 0, 1);
  gtk_widget_show(server_txt);

  port_txt = gtk_text_view_new();
  gtk_table_attach_defaults((GtkTable*)mainTab, port_txt, 1, 4, 1, 2);
  gtk_widget_show(port_txt);
  
  user_txt = gtk_text_view_new();
  gtk_table_attach_defaults((GtkTable*)mainTab, user_txt, 1, 4, 2, 3);
  gtk_widget_show(user_txt);

  ok_btn = gtk_button_new_with_label("OK");
  g_signal_connect(G_OBJECT(ok_btn), "clicked", G_CALLBACK(okconnect_cb), NULL);
  gtk_table_attach_defaults((GtkTable*)mainTab, ok_btn, 0, 2, 3, 4);
  gtk_widget_show(ok_btn);

  cancel_btn = gtk_button_new_with_label("Cancel");
  g_signal_connect(G_OBJECT(cancel_btn), "clicked", G_CALLBACK(closepopup_cb), (gpointer)w);
  gtk_table_attach_defaults((GtkTable*)mainTab, cancel_btn, 2, 4, 3, 4);
  gtk_widget_show(cancel_btn);

  gtk_widget_show(mainTab);
  gtk_widget_show(connectWin);
}
