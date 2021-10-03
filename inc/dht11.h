#ifndef DHT11_H_
#define DHT11_H_

#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "setagem.h"

// CONSTANTS 
#define MAX_TIMINGS	85
#define DEBUG 0
#define WAIT_TIME 2000

// FUNCTION DECLARATIONS
int init();
void printUsage();
int read_dht_data(setagem *params);

#endif /* DHT11_H_ */
