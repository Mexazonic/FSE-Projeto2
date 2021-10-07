#ifndef __GPIO__
#define __GPIO__

#include <wiringPi.h> //Used for GPIO
#include <softPwm.h>  //Used for GPIO
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include "cliente_tcp.h"
#include "setagem.h"
#include "config.h"

#define MAX_TIMINGS	85
#define DEBUG 0
#define WAIT_TIME 2000

void iniciar_gpio();
int ler_gpio(int pin);
void escrever_gpio(int pin, int signal);
void ligar_atuadores(setagem *params);
void *ler_sensores(void *args);
int read_dht_data(setagem *params);

#endif