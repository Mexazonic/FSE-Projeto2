#include "gpio.h"

void init_GPIO() {
    wiringPiSetup();

    /* Sensor de Presença Térreo */
    pinMode(25, INPUT);
    
    printf("GPIO Inicializada.\n");
}   

int read_gpio(int pin) {
    return digitalRead(pin);
}

void trigger_gpio(int pin, int signal) {
    digitalWrite(pin, signal);
}

void unbind_gpio()
{
    printf("gpio encerrada.\n");
}
