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
#include "gpio.h"

pthread_t th_servidor, sensores_th, atuadores_th;
setagem *params;

void iniciar(setagem *params);
void fechar(int signal);
void iniciar_threads(setagem *params);

#endif