#define _SERVER_H_
#include "mygtksockets.h"
/*
 * Author: Jeff Mariconda
 * Class: CS-392
 * 
 * Callback for when the "OK" button is clicked in the Connect window.
 * Gathers data from the entry fields and attempts to connect to the server.
 */
void okconnect_cb(GtkWidget *w, gpointer data)
{
  struct sockaddr_in serv_addr;
  struct hostent *server;
  char *servtxt, *porttxt, *usrtxt;
  char *buff;
  char err;
  int port;
  int n;

  servtxt = (char*)gtk_entry_buffer_get_text(gldata.servEnt);
  porttxt = (char*)gtk_entry_buffer_get_text(gldata.portEnt);
  usrtxt = (char*)gtk_entry_buffer_get_text(gldata.userEnt);
  
  if (my_strlen(servtxt) > 0 && my_strlen(porttxt) > 0 && my_strlen(usrtxt) > 0) {
    err = 0;
    
    //setup socket
    if ((sfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
      my_str("\nERROR: Unable to open socket.\n");
      exit(1);
    }

    //get server
    if ((server = gethostbyname(servtxt)) == NULL) {
      my_str("\nERROR: Could not find server. Please try entering again.\n");
      close(sfd);
      err = 1;
    }

    //get port
    port = my_atoi(porttxt);
    if (err != 1 && (port < 0 || port > 65535)) {
      my_str("\nERROR: Invalid Port. Please use a port from 0-65535\n");
      close(sfd);
      err = 1;
    }
    
    //initialize serv_addr struct elements
    if (err != 1) {
      memset(&serv_addr, 0, sizeof(serv_addr));
      serv_addr.sin_family = AF_INET;
      serv_addr.sin_port = htons(port);
      memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);
    }

    //connect to server
    if (err != 1 && connect(sfd, (struct sockaddr*)&serv_addr, (socklen_t)sizeof(serv_addr)) < 0) {
      my_str("\nERROR: Unable to connect to server.\n");
      close(sfd);
      err = 1;
    }

    //send username to server
    if (err != 1) {
      usrtxt = my_strconcat("/nick ", usrtxt);
      if ((n = write(sfd, usrtxt, my_strlen(usrtxt) + 1)) < 0) {
	my_str("\nERROR: Unable to write to server.\n");
	close(sfd);
	exit(1);
      }
      free(usrtxt);

      //check for server acknowledgement
      buff = xmalloc(256 * sizeof(char));
      alarm(5);
      if ((n = read(sfd, buff, 2)) > 0) {
	alarm(0);
      } else {
	my_str("\nERROR: Did not recieve acknowledgement from server.\n");
	close(sfd);
	exit(1);
      }
      free(buff);

      //destroy connect window once connection is established
      gldata.connected = 1;

      gtk_widget_destroy(gtk_widget_get_toplevel(w));
      g_signal_handler_block(gldata.cinst, gldata.cid);
      gtk_widget_set_sensitive((GtkWidget*)gldata.cinst, TRUE);
      gtk_widget_set_sensitive((GtkWidget*)gldata.sinst, TRUE);
      gtk_widget_set_sensitive((GtkWidget*)gldata.qinst, TRUE);
      gtk_toggle_button_set_active((GtkToggleButton*)gldata.cinst, TRUE);
      g_signal_handler_unblock(gldata.cinst, gldata.cid);      
    }
  } else {
    my_str("\nERROR: Please fill out all of the fields before clicking OK.\n");
  }
}
