
#ifndef DATA_H_
#define DATA_H_

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <time.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define INVALID_SOCKET -1
#define SOCKET_ERROR -1

#define PORT 80
typedef int SOCKET;
typedef struct sockaddr_in SOCKADDR_IN;
typedef struct sockaddr SOCKADDR;
		/* date.c */

char		 *get_date_system();

		/* error.c */

int		 log_error(char *msg, int status, char *file, char *flag, int display);
int		 log_std_error(char *str, int status, char *file, char *flag, int display);
char		 *get_date_system();

		/* main.c */

int		 main();

#endif /* DATA_H_ */
