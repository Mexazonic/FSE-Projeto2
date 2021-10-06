#ifndef CLIENTE_TCP_H
#define CLIENTE_TCP_H

#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int client_socket;
struct sockaddr_in servidorAddr;
int size;
int bytes_sent;

int enviar_parametros(const void *params);

#endif
