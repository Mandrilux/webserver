
#ifndef SERV_H_
#define SERV_H_

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define INVALID_SOCKET -1
#define SOCKET_ERROR -1

#define PORT 80
#define LOG_ACCESS "/var/log/serveur_acc.log"
#define LOG_ERROR "/var/log/serveur_err.log"
typedef int SOCKET;
typedef struct sockaddr_in SOCKADDR_IN;
typedef struct sockaddr SOCKADDR;

#endif /* SERV_H_ */