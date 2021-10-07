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
#include "constants.h"
#include "cliente_tcp.h"
#include "menu.h"

int server_socket, client_socket;
struct sockaddr_in serv_addr;

void *iniciar_servidor(void *central_setagem);

void close_server();

#endif