#define _SERVER_H_
#include "mygtksockets.h"
/*
 * Author: Jeff Mariconda
 * Class: CS-392
 *
 * Disconnects the client from the server.
 */
void disconnect()
{
  if (gldata.connected == 1) {
    close(sfd);
    gldata.connected = 0;
    
    g_signal_handler_block(gldata.cinst, gldata.cid);
    gtk_toggle_button_set_active((GtkToggleButton*)gldata.cinst, FALSE);
    g_signal_handler_unblock(gldata.cinst, gldata.cid);
  }
}
