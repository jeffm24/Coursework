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
  gtk_main_quit();
}
