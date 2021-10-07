#include "setagem.h"

void iniciar(setagem *params) {

    iniciar_gpio();

    params->AC_T_setagem = -1;
    params->ASP_setagem = -1;
    params->SP_T_setagem = -1;
    params->SF_T_setagem = -1;
    params->SJ_T01_setagem = -1;
    params->SJ_T02_setagem = -1;
    params->SPo_T_setagem = -1;
    params->temperatura = -0.0;
    params->humidade= 0.0;
    params->codigo_atuador = -1;
    params->pessoas = -1;
    params->SC_IN_setagem = -1;
    params->SC_OUT_setagem = -1;
    params->presence_alarm = 0;
    params->fire_alarm = 0;
    params->LS_T01_setagem = -1;
    params->LS_T02_setagem = -1;
    params->LC_T_setagem = -1;
    params->codigo_sensor = -1;    
}

void iniciar_threads(setagem *params) {}

void fechar(int signal){
    
    pthread_cancel(th_servidor);
    pthread_cancel(sensores_th);
    pthread_cancel(atuadores_th);

    free(params);
    close_server();

    printf("Conexões fechadas\n");
}