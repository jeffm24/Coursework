#define _CLIENT_H_
#include "mygtksockets.h"
/*
 * Author: Jeff Mariconda
 * Class: CS-392
 *
 * Server program for the basic IRC application.
 */

//Prints goodbye message and ends the parent server process.
void parent_bye() 
{
  my_str("\nReceived Interrupt. Now Exiting.\n\n");
  exit(0);
}

//Ends the child server process.
void child_bye()
{
  exit(0);
}

int main(int argc, char** argv)
{
  int port;
  struct sockaddr_in serv_addr, cli_addr;
  int cli_size;
  char *buff, *usr, **v;
  int pid, i, n;
  char init;

  if (argv != NULL && *argv != NULL && argc >= 2) {
    //get port 
    port = my_atoi(argv[1]);
    if (port < 1 || port > 64000) {
      my_str("\nERROR: Invalid Port. Please use:\n\t./server [port from 0-64000]\n\n");
      exit(1);
    }

    //setup socket
    if ((sfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
      my_str("\nERROR: Creating Socket Failed.\n\n");
      exit(1);
    }

    //initialize serv_addr struct elements
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    
    //bind socket to server address
    if (bind(sfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
      my_str("\nERROR: Binding Port Failed.\n\n");
      exit(1);
    } 
    
    my_str("\n----------------------------------------------------\n");
    my_str("WELCOME TO THE SIMPLE CHAT SERVER");
    my_str("\n----------------------------------------------------\n");
    my_str("\nServer accepting connections over port: ");
    my_int(port);
    my_str("\n\n");

    signal(SIGINT, parent_bye);
    
    //begin listening for clients
    listen(sfd, 5);
    while (1) {
      cli_size = (socklen_t)sizeof(cli_addr);
      
      //accept client connection
      if ((sfd2 = accept(sfd, (struct sockaddr*)&cli_addr, &cli_size)) < 0) {
	my_str("\nERROR: Failed to accept client connection.\n\n");
	close(sfd);
	exit(1);
      }
      
      //fork on client connection
      if ((pid = fork()) < 0) {
	my_str("\nERROR: Failed to fork.\n\n");
	close(sfd);
	close(sfd2);
	exit(1);
      } else if (pid == 0) {
	signal(SIGINT, child_bye);
	buff = xmalloc(256 * sizeof(char));
	init = 0;

	//begin child read loop for client
	while ((n = read(sfd2, buff, 256)) > 0) {
	  v = my_str2vect(buff);

	  //check for commands
	  if (my_strcmp(v[0], "/exit") == 0) {
	    my_str("***");
	    my_str(usr);
	    my_str(" Disconnected.\n\n");
	    exit(0);
	  } else if (my_strcmp(v[0], "/me") == 0) {
	    my_str("***");
	    my_str(usr);
	    my_str(": ");
	    my_str(&buff[4]);
	    my_str("\n\n");
	  } else if (my_strcmp(v[0], "/nick") == 0) {
	    if (init == 0) {
	      usr = my_strdup(&buff[6]);
	      my_str("***");
	      my_str(usr);
	      my_str(" Connected.\n\n");
	      init++;
	    } else {
	      my_str("***");
	      my_str(usr);
	      my_str(" changed name to ");
	      usr = my_strdup(&buff[6]);
	      my_str(usr);
	      my_str("\n\n");
	    }
	  } else if (my_strcmp(v[0], "/help") == 0) {
	    my_str("/exit : exit the chat\n");
	    my_str("/nick [name] : changes nickname to the given name\n");
	    my_str("/me [message] : prints message in the format, ***<User> <Message>\n");
	    my_str("[message] : prints message in the format, <User>: <Message>\n\n");
	  } else {
	    my_str(usr);
	    my_str(": ");
	    my_str(buff);
	    my_str("\n\n");
	  }
	  
	  if ((n = write(sfd2, "1", 2)) < 0) {
	    my_str("\nERROR: Server failed to acknowledge user: ");
	    my_str(usr);
	    my_char('\n');
	    break;
	  }

	  my_freevect(v);
	  v = NULL;
	}
	
	free(buff);
	close(sfd2);
	my_freevect(v);
	if (i != 0)
	  free(usr);
	break;
      }
    }
    
  } else {
    my_str("Invalid Input. Please use:\n\t./server [port from 0-64000]\n\n");
    exit(0);
  }
  
  return 0;
}
