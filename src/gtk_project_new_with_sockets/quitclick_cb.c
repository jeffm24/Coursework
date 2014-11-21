#define _SERVER_H_
#include "mygtksockets.h"
/*
 * Author: Jeff Mariconda
 * Class: CS-392
 *
 * Callback function for the Quit button click in the main client window.
 * Displays a popup window asking if the user is sure and gives them the 
 * option of clicking Yes or No.
 */
void quitclick_cb(GtkWidget *w, gpointer data)
{
  GtkWidget *quitWin;
  GtkWidget *mainTab;
  GtkWidget *label;
  GtkWidget *yes_btn, *no_btn;
  
  gtk_widget_set_sensitive((GtkWidget*)gldata.cinst, FALSE);
  gtk_widget_set_sensitive((GtkWidget*)gldata.qinst, FALSE);
  gtk_widget_set_sensitive((GtkWidget*)gldata.sinst, FALSE);

  quitWin = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_resizable((GtkWindow*)quitWin, FALSE);
  gtk_window_set_icon_from_file((GtkWindow*)quitWin, "icon.png", NULL);
  g_signal_connect(G_OBJECT(quitWin), "delete_event", G_CALLBACK(closepopup_cb), (gpointer)0);
  g_signal_connect(G_OBJECT(quitWin), "destroy", G_CALLBACK(closepopup_cb), (gpointer)0);
  gtk_container_set_border_width(GTK_CONTAINER(quitWin), 10);
  gtk_window_set_title(GTK_WINDOW(quitWin), "Wow.");

  mainTab = gtk_table_new(2, 2, FALSE);
  gtk_container_add(GTK_CONTAINER(quitWin), mainTab);
  gtk_table_set_row_spacings((GtkTable*)mainTab, 5);
  gtk_table_set_col_spacings((GtkTable*)mainTab, 5);

  label = gtk_label_new("Are you sure?");
  gtk_table_attach_defaults((GtkTable*)mainTab, label, 0, 2, 0, 1);
  gtk_widget_show(label);

  yes_btn = gtk_button_new_with_label("Yes");
  g_signal_connect(G_OBJECT(yes_btn), "clicked", G_CALLBACK(destroy_cb), NULL);
  gtk_table_attach_defaults((GtkTable*)mainTab, yes_btn, 0, 1, 1, 2);
  gtk_widget_show(yes_btn);

  no_btn = gtk_button_new_with_label("No");
  g_signal_connect(G_OBJECT(no_btn), "clicked", G_CALLBACK(closepopup_cb), (gpointer)0);
  gtk_table_attach_defaults((GtkTable*)mainTab, no_btn, 1, 2, 1, 2);
  gtk_widget_show(no_btn);

  gtk_widget_show(mainTab);
  gtk_widget_show(quitWin);
}
