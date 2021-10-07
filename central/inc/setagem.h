#ifndef SETAGEM_H_
#define SETAGEM_H_

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <pthread.h>
#include "socket.h"
#include "cliente_tcp.h"
#include "setagem.h"
#include "gpio.h"
#include "menu.h"
#include "csv.h"

// Andar Terreo
#define LS_T01 7
#define LS_T02 0
#define LC_T 2
#define AC_T 11
#define ASP 27
#define SP_T 25
#define SF_T 4
#define SJ_T01 13
#define SJ_T02 14
#define SPo_T 12
#define SC_IN 23
#define SC_OUT 24

// Primeiro Andar
#define LS_101 22
#define LS_102 25
#define LC_1 08
#define AC_1 12
#define SP_1 18
#define SF_1 24
#define SJ_1 05
#define SJ_2 06

#define PIN_DHT11_1 28
#define PIN_DHT11_2 29

#define TEMP_HUM 20
#define PESSOAS_IDENTIFICADOR 1
#define ALARME_PRESENCE 2
#define ALARME_FIRE 3

typedef struct {
    float temperatura;
    float humidade;
    int pessoas;
    int SC_IN_setagem;
    int SC_OUT_setagem;
    int presence_alarm;
    int fire_alarm;
    int LS_T01_setagem;
    int LS_T02_setagem;
    int LC_T_setagem;
    int AC_T_setagem;
    int ASP_setagem;
    int SP_T_setagem;
    int SF_T_setagem;
    int SJ_T01_setagem;
    int SJ_T02_setagem;
    int SPo_T_setagem;
    int identificador;

} setagem;

pthread_t thread_servidor, thread_menu;
setagem *estado;

void iniciar(setagem *estado);
void fechar(int signal);
void gerenciar_estado(setagem *buffer, setagem *atual_estado);

#endif