#ifndef _MYSOCKETS_H_
#define _MYSOCKETS_H_

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

int sfd;

void client_bye(int);

#endif
