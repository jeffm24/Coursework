#define _SERVER_H_
#include "mygtksockets.h"
/*
 * Author: Jeff Mariconda
 * Class: CS-392
 *
 * Gets the toplevel container of the GtkWidget provided and deletes that along 
 * with all of its children. 
 */
gint closepopup_cb(GtkWidget *w, gpointer data)
{
  GtkWidget *toplvl;
  GList *children, *it;
  GtkToggleButton *button = (GtkToggleButton*)data;

  if (w != NULL) {
    
    if (button != NULL && my_strcmp("Connect", (char*)gtk_button_get_label((GtkButton*)button)) == 0) {
      gtk_toggle_button_set_active(button, FALSE);
    }

    toplvl = gtk_widget_get_toplevel(w);
    if (gtk_widget_is_toplevel(toplvl)) {
      children = gtk_container_get_children(GTK_CONTAINER(toplvl));
      
      for (it = children ; it != NULL ; it = g_list_next(it))
	gtk_widget_destroy(GTK_WIDGET(it->data));
      
      g_list_free(children);
      gtk_widget_destroy(toplvl);
    }
  }
  return TRUE;
}
