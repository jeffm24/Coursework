#define _SERVER_H_
#include "mygtksockets.h"
/*
 * Author: Jeff Mariconda
 * Class: CS-392
 *
 * Callback for when the send button is clicked in the main client window.
 * Sends the message from the text box to the server if connected.
 */
void sendclick_cb(GtkWidget *w, gpointer data)
{
  char *msgtxt, *buff;
  char **v;
  int n;

  msgtxt = (char*)gtk_entry_buffer_get_text(gldata.msgEnt);
  if (gldata.connected == 1 && my_strlen(msgtxt) != 0) {
    
    //check for special cases
    v = my_str2vect(msgtxt);
    for (; *msgtxt == ' ' || *msgtxt == '\t' ; msgtxt++)
      ;
      
    if (my_strcmp(v[0], "/exit") == 0) {
      if ((n = write(sfd, "/exit", 6)) < 0) {
	my_str("\nERROR: Unable to send message to server.\n");
      }
      disconnect();
    }

    my_freevect(v);

    //write message to server
    if (gldata.connected == 1 && (n = write(sfd, msgtxt, my_strlen(msgtxt) + 1)) < 0) {
      my_str("\nERROR: Unable to send message to server.\n");
      disconnect();
    }
    
    if (gldata.connected == 1) {
      buff = xmalloc(256 * sizeof(char));
      
      //check for server acknowledgement
      alarm(5);
      if ((n = read(sfd, buff, 2)) > 0) {
	alarm(0);
      } else {
	my_str("\nERROR: Did not recieve acknowledgement from server.\n");
	disconnect();
      }
      
      free(buff);
    }
  }
}
