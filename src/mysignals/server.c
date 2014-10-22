#include "mysignals.h"

/*
 * Author: Jeff Mariconda
 * Class: CS-392
 *
 * Server program. Waits for clients to connect, receives messages from them, and prints the messages.
 */
int main() 
{
	int i;

	my_str("\n----------------------------------------------------------------------------\n");
	my_str("Server Started...\n\n");
	my_str("PID: ");
	my_int(getpid());
	my_str("\n----------------------------------------------------------------------------\n");
	signal(SIGINT, sbye);

	while (1) {
		gl_env.done = 0;
		gl_env.clipid = 0;
		
		signal(SIGUSR1, get_clipid);
		signal(SIGUSR2, get_clipid);
		for (i = 0 ; i < (8 * sizeof(int)) ; i++)
			pause();
		
		my_str("\nClient ");
        my_int(gl_env.clipid);
        my_str(" sent: ");	
		
		signal(SIGUSR1, get_char);
		signal(SIGUSR2, get_char);
		
		usleep(1000);
		kill(gl_env.clipid, SIGUSR1);
		
		while (!gl_env.done){
			pause();
		}
		my_str("\n\n");
	}
	return 0;
}
