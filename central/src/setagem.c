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
    
    criar_arquivo();
}

void fechar(int signal){
    pthread_cancel(thread_servidor);
    pthread_cancel(thread_menu);
    fechar_servidor_distribuido();
}

void gerenciar_estado(setagem *novo_estado, setagem *atual_estado) {
	
    if(novo_estado->identificador == TEMP_HUM) {
        atual_estado->temperatura = novo_estado->temperatura;
		atual_estado->humidade = novo_estado->humidade;
    } else if (novo_estado->identificador == PESSOAS_IDENTIFICADOR) {
        atual_estado->pessoas = novo_estado->pessoas;
    } else if (novo_estado->identificador == SP_T) {
        atual_estado->SP_T_setagem = novo_estado->SP_T_setagem;
    } else if (novo_estado->identificador == SF_T) {
        atual_estado->SF_T_setagem = novo_estado->SF_T_setagem;
    } else if (novo_estado->identificador == SJ_T01) {
        atual_estado->SJ_T01_setagem = novo_estado->SJ_T01_setagem;
    } else if (novo_estado->identificador == SJ_T02) {
        atual_estado->SJ_T02_setagem = novo_estado->SJ_T02_setagem;
    } else if (novo_estado->identificador == SPo_T) {
        atual_estado->SP_T_setagem = novo_estado->SPo_T_setagem;
    }
}
