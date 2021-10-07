
#ifndef MENU_H_
#define MENU_H_

#include <stdio.h>
#include <stdlib.h>
#include "cliente_tcp.h"
#include "config.h"
#include "csv.h"
#include "constants.h"

void *carregar_menu(void *args);
void menu(setagem *params);
void ligar_desligar();

#endif