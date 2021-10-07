#include "setagem.h"

void iniciar(setagem *estado) {

    estado->LS_T01_setagem = 0;
    estado->LS_T02_setagem = 0;
    estado->LC_T_setagem = 0;
    estado->AC_T_setagem = 0;
    estado->ASP_setagem = 0;
    estado->SP_T_setagem = 0;
    estado->SF_T_setagem = 0;
    estado->SJ_T01_setagem = 0;
    estado->SJ_T02_setagem = 0;
    estado->SPo_T_setagem = 0;
    estado->identificador = -1;
    estado->temperatura = -0.0;
    estado->humidade = 0.0;
    estado->pessoas = 0;
    estado->SC_IN_setagem = 0;
    estado->SC_OUT_setagem = 0;
    estado->presence_alarm = 0;
    estado->fire_alarm = 0;

    iniciar_gpio();
}

void encerrar(int signal){
    pthread_cancel(thread_servidor);
    pthread_cancel(thread_leitura_sensores);
    fechar_servidor_distribuido();
}