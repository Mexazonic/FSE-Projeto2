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
#include "constants.h"
#define DELAY_5 5000000

void init_GPIO();
int read_gpio(int pin);
void trigger_gpio(int pin, int signal);

void unbind_gpio();

#endif // __GPIO__