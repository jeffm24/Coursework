#include "mysignals.h"

/*
 * Author: Jeff Mariconda
 * Class: CS-392
 *
 * Pre: Takes the server's pid.
 * Post: Sends the client's pid bit-by-bit, using SIGUSR1 for 1's and SIGUSR2 for 0's
 */
void send_pid(pid_t spid)
{	
    int cpid = getpid();
    pid_t mask = 1 << ((sizeof(int) * 8) - 1);;
    int i;
    
    for (i = 0 ; i < (sizeof(int) * 8) ; i++) {
        usleep(5000);
        if (cpid & mask)
            kill(spid, SIGUSR1);
        else
            kill(spid, SIGUSR2);

        cpid <<= 1;
    }
}
