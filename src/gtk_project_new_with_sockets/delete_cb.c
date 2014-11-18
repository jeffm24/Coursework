#define _SERVER_H_
#include "mygtksockets.h"
/*
 * Author: Jeff Mariconda
 * Class: CS-392
 *
 * Callback function for clicking the "X" on the main window.
 * Prints and error message telling the user to click the Quit button instead.
 */
gint delete_cb(GtkWidget *w, gpointer data)
{
  g_print("Please click the \"Quit\" button to exit the program.\n");
  return TRUE;
}
