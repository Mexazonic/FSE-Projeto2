#ifndef CLIENTE_TCP_H_
#define CLIENTE_TCP_H_

#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "setagem.h"
#include "config.h"

int client_socket;
struct sockaddr_in servidorAddr;
int size;
int bytes_sent;

int enviar_dado_tcp(const void *message);

#endif
