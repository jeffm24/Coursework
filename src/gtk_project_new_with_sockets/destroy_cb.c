#define _SERVER_H_
#include "mygtksockets.h"
/*
 * Author: Jeff Mariconda
 * Class: CS-392
 *
 * Callback function for qutting the program.
 */
void destroy_cb(GtkWidget *w, gpointer data)
{
  int n;

  if (gldata.connected == 1) {
    if ((n = write(sfd, "/exit", 6)) < 0)
      my_str("\nERROR: Unable to send message to server.\n");
    close(sfd);
  }
  gtk_main_quit();
}
