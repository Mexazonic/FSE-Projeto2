#ifndef SOCKET_H_
#define SOCKET_H_

#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "constants.h"
#include "config.h"
#include "cliente_tcp.h"
#include "constants.h"

int server_socket, client_socket;
struct sockaddr_in serv_addr;

void *iniciar_servidor(void *args);
void close_server();

#endif