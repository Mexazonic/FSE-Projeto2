#ifndef __GPIO__
#define __GPIO__

/*
  Control Intensity of LED using PWM on Raspberry pi
  http://www.electronicwings.com
 */

#include <wiringPi.h> //Used for GPIO
#include <softPwm.h>  //Used for GPIO
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include <pthread.h>
#include "config.h"
#include "constants.h"
#include "cliente_tcp.h"

#define DELAY_5 5000000
#define MAX_TIMINGS	85
#define DEBUG 0
#define WAIT_TIME 2000

int read_dht_data(setagem *params);
void iniciar_gpio();
int ler_gpio(int pin);
void ligar_desligar_gpio(int pin, int signal);
void *ativar_atuadores(void *args);
void *ler_sensores(void *args);

#endif // __GPIO__