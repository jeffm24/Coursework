#define _SERVER_H_
#include "mygtksockets.h"
/*
 * Author: Jeff Mariconda
 * Class: CS-392
 *
 * Gets the toplevel container of the GtkWidget provided and deletes it. 
 */
gint closepopup_cb(GtkWidget *w, gpointer data)
{
  GtkWidget *toplvl;
  GtkToggleButton *button = (GtkToggleButton*)data;

  if (w != NULL) {
    if (my_strcmp("Connect", (char*)gtk_button_get_label((GtkButton*)button)) == 0) {
      gtk_toggle_button_set_active(button, FALSE);
      g_signal_handler_unblock(gldata.cinst, gldata.cid);
    } 
        
    gtk_widget_set_sensitive((GtkWidget*)gldata.cinst, TRUE);
    gtk_widget_set_sensitive((GtkWidget*)gldata.sinst, TRUE);
    gtk_widget_set_sensitive((GtkWidget*)gldata.qinst, TRUE);
    
    toplvl = gtk_widget_get_toplevel(w);
    gtk_widget_destroy(toplvl);
  }
  return TRUE;
}
