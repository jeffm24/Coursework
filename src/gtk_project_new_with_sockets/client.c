#define _SERVER_H_
#include "mygtksockets.h"
/*
 * Author: Jeff Mariconda
 * Class: CS-392
 *
 * Client program for the basic IRC application.
 */

//Prints goodbye message and ends the client on SIGINT or SIGALRM.
void client_bye(int sig)
{
  int m;

  if (sig == SIGINT) {
    my_str("\nReceived Interrupt. Now Exiting.\n\n");
  }

  if ((m = write(sfd, "/exit", 6) < 0)) {
    my_str("\nERROR: Unable to send message to server.\n");
  }

  gtk_main_quit();
}

int main(int argc, char **argv)
{
  int n;
  char *buff, *usr, *temp, **v;

  GtkWidget *win;
  GtkWidget *mainTab;
  GtkWidget *label;
  GtkWidget *text;
  GtkWidget *send_btn, *cnct_btn, *quit_btn;

  signal(SIGINT, client_bye);
  gldata.connected = 0;

  gtk_init(&argc, &argv);
  
  win = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_resizable((GtkWindow*)win, FALSE);
  g_signal_connect(G_OBJECT(win), "delete_event", G_CALLBACK(delete_cb), NULL);
  g_signal_connect(G_OBJECT(win), "destroy", G_CALLBACK(destroy_cb), NULL);
  gtk_container_set_border_width(GTK_CONTAINER(win), 10);
  gtk_window_set_title(GTK_WINDOW(win), "#Basic Chat");

  mainTab = gtk_table_new(3, 6, FALSE);
  gtk_container_add(GTK_CONTAINER(win), mainTab);
  gtk_table_set_row_spacings((GtkTable*)mainTab, 5);
  gtk_table_set_col_spacings((GtkTable*)mainTab, 5);

  label = gtk_label_new("Message:");
  gtk_table_attach_defaults((GtkTable*)mainTab, label, 0, 2, 0, 1);
  gtk_widget_show(label);
  
  text = gtk_entry_new();
  g_signal_connect(G_OBJECT(text), "activate", G_CALLBACK(sendclick_cb), NULL);
  gtk_table_attach_defaults((GtkTable*)mainTab, text, 0, 4, 1, 2);
  gldata.msgEnt = gtk_entry_get_buffer((GtkEntry*)text);
  gtk_widget_show(text);

  send_btn = gtk_button_new_with_label("Send");
  gldata.sid = g_signal_connect(G_OBJECT(send_btn), "clicked", G_CALLBACK(sendclick_cb), NULL);
  gldata.sinst = (gpointer)send_btn;
  gtk_table_attach_defaults((GtkTable*)mainTab, send_btn, 4, 6, 1, 2);
  gtk_widget_show(send_btn);

  cnct_btn = gtk_toggle_button_new_with_label("Connect");
  gldata.cid = g_signal_connect(G_OBJECT(cnct_btn), "clicked", G_CALLBACK(connectclick_cb), NULL);
  gldata.cinst = (gpointer)cnct_btn;
  gtk_table_attach_defaults((GtkTable*)mainTab, cnct_btn, 1, 3, 2, 3);
  gtk_widget_show(cnct_btn);

  quit_btn = gtk_button_new_with_label("Quit");
  gldata.qid = g_signal_connect(G_OBJECT(quit_btn), "clicked", G_CALLBACK(quitclick_cb), NULL);
  gldata.qinst = (gpointer)quit_btn;
  gtk_table_attach_defaults((GtkTable*)mainTab, quit_btn, 3, 5, 2, 3);
  gtk_widget_show(quit_btn);

  gtk_widget_show(mainTab);
  gtk_widget_show(win);

  gtk_main();

  return 0;
}
