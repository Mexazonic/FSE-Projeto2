#ifndef TCP_CLIENT_H_
#define TCP_CLIENT_H_

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

int enviar_dados_tcp(const void *message);

#endif
