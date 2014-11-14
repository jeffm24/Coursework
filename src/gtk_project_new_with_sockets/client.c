#define _SERVER_H_
#include "mysockets.h"
/*
 * Author: Jeff Mariconda
 * Class: CS-392
 *
 * Client program for the basic IRC application.
 */

//Prints goodbye message and ends the client on SIGINT.
void client_bye(int sig)
{
  int m;

  if (sig == SIGINT) {
    my_str("\nReceived Interrupt. Now Exiting.\n\n");
  } else if (sig == SIGALRM) {
    my_str("\nERROR: Did not receive acknowledgement from server.\n\n");
  }

  if ((m = write(sfd, "/exit", 6) < 0)) {
    my_str("\nERROR: Unable to send message to server.\n");
  }

  exit(0);
}

int main(int argc, char **argv)
{
  struct sockaddr_in serv_addr;
  struct hostent *server;
  int port, n;
  char *buff, *usr, *temp, **v;
  
  if (argv != NULL && *argv != NULL && argc == 3) {
    signal(SIGINT, client_bye);
    signal(SIGALRM, client_bye);
    
    //setup socket
    if ((sfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
      my_str("\nERROR: Unable to open socket.\n\n");
      exit(1);
    }

    //get server
    if ((server = gethostbyname(argv[1])) == NULL) {
      my_str("\nERROR: Could not find server. Please use:\n\t./client [servername] [port]\n\n");
      close(sfd);
      exit(1);
    }

    //get port
    port = my_atoi(argv[2]);
    if (port < 1 || port > 64000) {
      my_str("\nERROR: Invalid Port. Please use:\n\t./client [servername] [port from 0-64000]\n\n");
      close(sfd);
      exit(1);
    }
    
    //initialize serv_addr struct elements
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);

    //connect to server
    if (connect(sfd, (struct sockaddr*)&serv_addr, (socklen_t)sizeof(serv_addr)) < 0) {
      my_str("\nERROR: Unable to connect to server.\n\n");
      close(sfd);
      exit(1);
    }

    my_str("\n----------------------------------------------------\n");
    my_str("WELCOME TO SIMPLE CHAT CLIENT");
    my_str("\n----------------------------------------------------\n");

    buff = xmalloc(256 * sizeof(char));
    my_str("\nUsername: ");
    
    //read in username and send it to server
    if ((n = read(0, buff, 256)) < 0) {
      my_str("\nERROR: Could not read username.\n\n");
      close(sfd);
      exit(1);
    }
    
    usr = my_vect2str(my_str2vect(buff));
    temp = my_strconcat("/nick ", usr);
    if ((n = write(sfd, temp, my_strlen(temp) + 1)) < 0) {
      my_str("\nERROR: Unable to write to server.\n\n");
      close(sfd);
      exit(1);
    }
    free(temp);
    
    //check for server acknowledgement
    alarm(5);
    if ((n = read(sfd, buff, 2)) > 0) {
      alarm(0);
    } else {
      my_str("\nERROR: Did not recieve acknowledgement from server.\n");
      close(sfd);
      exit(1);
    }
    
    my_str("\nYou are now connected to ");
    my_str(argv[1]);
    my_str(". Enter /help for a list of commands.\n\n");

    //begin input loop
    while (1) {
      my_str(usr);
      my_str(": ");

      memset(buff, 0, 256);
      //read user input
      if ((n = read(0, buff, 256)) < 0) {
	my_str("\nERROR: Unable to read input.\n");
	break;
      } else if (n == 1) {
	continue;
      }
      
      //check for special cases
      v = my_str2vect(buff);
      for (; *buff == ' ' || *buff == '\t' ; buff++)
	  ;
      buff[my_strlen(buff) - 1] = '\0';
      
      if (my_strcmp(v[0], "/nick") == 0) {
	free(usr);
	usr = my_strdup(&buff[6]);
      } else if (my_strcmp(v[0], "/exit") == 0) {
	my_str("\nThanks for using the simple chat client. Goodbye.\n");
	if ((n = write(sfd, buff, my_strlen(buff) + 1)) < 0) {
	  my_str("\nERROR: Unable to send message to server.\n");
	}
	break;
      }

      //write message to server
      if ((n = write(sfd, buff, my_strlen(buff) + 1)) < 0) {
	my_str("\nERROR: Unable to send message to server.\n");
        break;
      }
      
      //check for server acknowledgement
      alarm(5);
      if ((n = read(sfd, buff, 2)) > 0) {
	alarm(0);
      } else {
	my_str("\nERROR: Did not recieve acknowledgement from server.\n");
	close(sfd);
	exit(1);
      }
            
      my_freevect(v);
    }

  } else {
    my_str("\nInvalid Input. Please use:\n\t./client [servername] [port]\n\n");
    exit(0);
  }
  
  close(sfd);
  free(buff);
  free(usr);
  my_freevect(v);
  return 0;
}
