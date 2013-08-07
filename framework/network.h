#ifndef _NETWORK_H_
#define _NETWORK_H_

#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <arpa/inet.h>          // htons
#include <string.h>
#include <netinet/tcp.h>        // TCP option
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <string.h>
#include <sys/epoll.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/stat.h>



#define LISTENQ  128            // second argument to listen()

// Simplifies calls to bind(), connect(), and accept()
typedef struct sockaddr SA;

int epoll_start(int listen_sock);
void make_socket_non_blocking(int sfd);
int open_non_blocking_socket(int port);

void accept_incoming(int listen_sock, int epoll_fd);
void close_and_clean(int fd);

int read_all(int fd,char *buf);
int send_all(int fd,char *buf);

#endif /* _NETWORK_H_ */
