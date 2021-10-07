
#ifndef CSV_H_
#define CSV_H_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

time_t seed;
struct tm *args;
char datetime[80];

void atualizar_log(char * command, int value);
void criar_arquivo();

#endif