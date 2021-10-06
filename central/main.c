#include <stdio.h>
#include <string.h>
#include "../inc/setagem.h"
#include "../inc/gpio.h"
#include "../inc/dht11.h"
#include "../inc/default.h"
#include "../inc/servidor_tcp.h"
#include "../inc/cliente_tcp.h"



void config();
void close_connections();
void sensores();

int main() {
    
    //init_GPIO();
    setagem *params = (setagem *) malloc(sizeof(setagem));

    /* Initial Setup */
	//config(params);
    //sensores(params);
    //start_socket(10103);

    enviar_parametros((void *) params);
    //unbind_gpio();

    return 0;
}

void config(setagem *params) {

    params->run = 0;
    

    params->temperatura = 10.0;
    params->umidade = 100.0;
    params->pessoas = 0;

    params->LS_T01_estado = 0;
    params->SC_IN_estado = 0;
    params->SC_OUT_estado = 0;
    params->LS_T02_estado = 1;
    params->LC_T_estado = 1;
    params->AC_T_estado = 0;
    params->ASP_estado = 1;
    params->SP_T_estado = 1;
    params->SF_T_estado = 1;
    params->SJ_T01_estado = 1;
    params->SJ_T02_estado = 1;
    params->SPo_T_estado = 1;

  
	usleep(1000000);
}

