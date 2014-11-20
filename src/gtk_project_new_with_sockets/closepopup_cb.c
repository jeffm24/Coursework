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
  if (w != NULL) {
    
    //check if the closepopup callback came from the Connect window
    if (data == (gpointer)1) {  
      gtk_toggle_button_set_active((GtkToggleButton*)gldata.cinst, FALSE);
      g_signal_handler_unblock(gldata.cinst, gldata.cid);
    } 
        
    //make all buttons active again
    gtk_widget_set_sensitive((GtkWidget*)gldata.cinst, TRUE);
    gtk_widget_set_sensitive((GtkWidget*)gldata.sinst, TRUE);
    gtk_widget_set_sensitive((GtkWidget*)gldata.qinst, TRUE);
    
    //destroy toplevel window
    gtk_widget_destroy(gtk_widget_get_toplevel(w));
  }
  return TRUE;
}
