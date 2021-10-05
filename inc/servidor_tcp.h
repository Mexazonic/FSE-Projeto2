#ifndef TCP_SERVER_H_
#define TCP_SERVER_H_

#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "default.h"
#include "setagem.h"

// Exemplo Professor
int servidorSocket;
int socketCliente;
struct sockaddr_in servidorAddr;
struct sockaddr_in clienteAddr;
unsigned short servidorPorta;
unsigned int clienteLength;

void start_socket(unsigned short port);

#endif 