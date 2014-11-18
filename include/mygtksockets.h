#ifndef _MYGTKSOCKETS_H_
#define _MYGTKSOCKETS_H_

#include "my.h"
#include <signal.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

#endif

#ifndef _SERVER_H_
#define _SERVER_H_

int sfd, sfd2;

void parent_bye();
void child_bye();

#endif

#ifndef _CLIENT_H_
#define _CLIENT_H_

#include <netdb.h>
#include <gtk/gtk.h>

int sfd;

//Callback function for the client recieving a SIGINT OR SIGALRM from the server
void client_bye(int);

//Callback for completly terminating the program and GUI
void destroy_cb(GtkWidget*, gpointer);

//Callback for destroying a popup window
gint closepopup_cb(GtkWidget*, gpointer);

/*
 *----------------------------------------------------------
 * GTK CALLBACK FUNCTIONS FOR THE MAIN CLIENT WINDOW:
 *----------------------------------------------------------
 */

//Handles when the "X" is clicked
gint delete_cb(GtkWidget*, gpointer);

//Handles when the "Send" button is clicked
gint sendclick_cb(GtkWidget*, gpointer);

//Handles when the "Connect" button is clicked
void connectclick_cb(GtkWidget*, gpointer);

//Handles when the "Quit" button is clicked
void quitclick_cb(GtkWidget*, gpointer);

/*
 *----------------------------------------------------------
 * GTK CALLBACK FUNCTIONS FOR THE CONNECT POPUP DIALOGUE:
 *----------------------------------------------------------
 */

//Handles when the "OK: button is clicked
void okconnect_cb(GtkWidget*, gpointer);

#endif
