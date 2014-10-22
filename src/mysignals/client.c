#include "mysignals.h"

/*
 * Author: Jeff Mariconda
 * Class: CS-392
 *
 * Client Program. Connects to the specified server program and sends it a message to print.
 */
int main(int argc, char **argv)
{
	int i;
    int spid;
    char *s;
	
	if (argc >= 3) {		
		spid = my_atoi(argv[1]);
		s = my_vect2str(&argv[2]);
		gl_env.ack = 0;
		
		signal(SIGUSR1, acknowledge);
		signal(SIGALRM, cbye);
		
		my_str("\n----------------------------------------------------------------------------\n");
		my_str("Client Started...\n\n");
		my_str("PID: ");
		my_int(getpid());
		my_str("\n----------------------------------------------------------------------------\n");
		
		send_pid(spid); 
		
		if (!gl_env.ack) {
			alarm(2);
			pause();
		}
		
		alarm(0);

		for (i = 0; s[i] != '\0'; i++) {
			send_char(s[i], spid);
			alarm(2);
		}
		send_char('\0', spid);
    
	} else {
		my_str("\nInvalid Format. Please use: ./client [server_pid] [args]\n\n");
		exit(1);
	}

	return 0;
}
