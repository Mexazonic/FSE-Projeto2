#ifndef SETAGEM_H_
#define SETAGEM_H_

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <pthread.h>
#include "socket.h"
#include "cliente_tcp.h"
#include "constants.h"
#include "config.h"
#include "menu.h"
#include "csv.h"

setagem *params;
pthread_t th_servidor, menu_thread;

void iniciar(setagem *params);
void fechar(int signal);
void iniciar_threads(setagem *params);

#endif